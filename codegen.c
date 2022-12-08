#include "codegen.h"
#include "typecheck.h"
#include "expr.h"
#include <stdlib.h>

int num_args = 0;
int label_count = 0;
int scratches[7] = {0};

void decl_codegen(struct decl *d, int segment)
{
    if(!d) return;

    if(d->symbol->kind == SYMBOL_GLOBAL) {
        if (d->code) {
            num_args = d->param_count;
            if(segment != 0) {
                segment = 0;
                printf("\n.text\n");
            }
            printf(".global %s\n", d->name);
            printf("%s: \n", d->name);
            function_preamble_codegen(d);

            printf("\n");

            stmt_codegen(d->code, d);
            function_epilogue_codegen(d);
        } else {
            if(segment != 1) {
                segment = 1;
                printf("\n.data\n");
            }
            switch(d->type->kind) {
                case TYPE_INTEGER:
                case TYPE_BOOLEAN:
                case TYPE_CHARACTER:
                    if(d->value) {
                        printf("%s: .quad %d\n", d->name, d->value->literal_value);
                    } else {
                        printf("%s: .quad 0\n", d->name);
                    }
                    break;
                case TYPE_ARRAY:
                    printf("%s: ", d->name);
                    if(d->value) {
                        printf(".quad ");
                        struct expr *curr = d->value->mid;
                        while(curr && curr->mid) {
                            printf("%d, ", curr->left->literal_value);
                            curr = curr->mid;
                        }
                        if(curr) {
                            printf("%d", curr->left->literal_value);
                        }
                        printf("\n");
                    } else {
                        printf(".quad");
                        for(int i = 0; i < d->type->expr->literal_value - 1; i++) {
                            printf("0, ");
                        }
                        printf("0");
                    }
                    break;
                case TYPE_STRING: {
                    int str_lab = label_create();
                    printf("%s: .quad %s\n", d->name, label_name(str_lab) );
                    printf("\n%s: .string \"%s\"\n", label_name(str_lab), print_string(d->value->string_literal) );
                    break;\
                }
            }
        }
    } else if (d->symbol->kind == SYMBOL_LOCAL) {
        if(!d->value) {
            d->value = expr_create_integer_literal(0);
        }
        expr_codegen(d->value);
        printf("MOVQ %s, %s\n", scratch_name(d->value->reg), symbol_codegen(d->symbol) );
        scratch_free(d->value->reg);
    }
    decl_codegen(d->next, segment);
}

void function_preamble_codegen(struct decl *d)
{
    printf("PUSHQ %%rbp\n");
    printf("MOVQ %%rsp, %%rbp\n\n");

    char *arg_regs[6] = { "%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9" };
    for(int i = 0; i < d->param_count && i < 6; i++) {
        printf("PUSHQ %s\n", arg_regs[i] );
    }
    printf("\n");

    printf("SUBQ $%d, %%rsp\n\n", 8 * d->local_count);
    printf("PUSHQ %%rbx\n");
    printf("PUSHQ %%r12\n");
    printf("PUSHQ %%r13\n");
    printf("PUSHQ %%r14\n");
    printf("PUSHQ %%r15\n");
}

void function_epilogue_codegen(struct decl *d)
{
    printf("\n.%s_epilogue:\n", d->name);
    printf("POPQ %%r15\n");
    printf("POPQ %%r14\n");
    printf("POPQ %%r13\n");
    printf("POPQ %%r12\n");
    printf("POPQ %%rbx\n");

    printf("MOVQ %%rbp, %%rsp\n\n");
    printf("POPQ %%rbp\n");

    printf("RET\n\n");
}

void stmt_codegen(struct stmt *s, struct decl *func)
{
    if(!s) return;
    
    switch (s->kind) {
        case STMT_RETURN:
            if (s->expr) {
                expr_codegen(s->expr);
                printf("MOVQ %s, %%rax\n", scratch_name(s->expr->reg));
                scratch_free(s->expr->reg);
            }
            printf("JMP .%s_epilogue\n", func->name);
            break;
        case STMT_DECL:
            decl_codegen(s->decl, 0);
            break;
        case STMT_EXPR:
            expr_codegen(s->expr);
            scratch_free(s->expr->reg);
            break;
        case STMT_BLOCK:
            stmt_codegen(s->body, func);
            break;
        case STMT_PRINT:
            print_codegen(s);
            break;
        case STMT_FOR:
            for_loop_codegen(s, func);
            break;
        case STMT_IF_ELSE:
            if_else_codegen(s, func);
            break;
    }
    stmt_codegen(s->next, func);
}

void print_codegen(struct stmt *s)
{
    if(!s) return;
    struct expr *curr = s->expr;
    while (curr) {
        struct type *t1 = expr_typecheck(curr->left);
        type_t t2 = t1->kind;
        struct expr *e;
        if(t2 == TYPE_INTEGER) {
            e = expr_create_func("print_integer",
                 expr_create_args(curr->left, NULL) );
        } else if (t2 == TYPE_CHARACTER) {
            e = expr_create_func("print_character",
                 expr_create_args(curr->left, NULL));
        } else if (t2 == TYPE_STRING) {
            e = expr_create_func("print_string",
                 expr_create_args(curr->left, NULL));
        } else if (t2 == TYPE_BOOLEAN) {
            e = expr_create_func("print_boolean",
                 expr_create_args(curr->left, NULL));
        }
        expr_codegen(e);
        scratch_free(e->reg);
        curr = curr->mid;
    }
}

void if_else_codegen(struct stmt *s, struct decl *func)
{
    struct expr *e = s->expr;
    expr_codegen(e);
    int true_label = label_create();
    printf("CMP $1, %s\n", scratch_name(e->reg) );
    printf("JE %s\n", label_name(true_label) );
    if(s->else_body) {
        stmt_codegen(s->else_body, func);
    }
    int end_label = label_create();
    printf("JMP %s\n", label_name(end_label) );
    printf("%s:\n", label_name(true_label) );
    stmt_codegen(s->body, func);
    printf("%s:\n", label_name(end_label) );
    scratch_free(e->reg);
}
void for_loop_codegen(struct stmt *s, struct decl *func)
{
    if(s->init_expr) {
        expr_codegen(s->init_expr);
        scratch_free(s->init_expr->reg);
    }
    int top_label = label_create();
    int done_label = label_create();
    if (!s->expr) {
        s->expr = expr_create_boolean_literal("true");
    }
    printf("%s:\n", label_name(top_label) );
    expr_codegen(s->expr);
    printf("CMP $0, %s\n", scratch_name(s->expr->reg));
    printf("JE %s\n", label_name(done_label));
    scratch_free(s->expr->reg);

    stmt_codegen(s->body, func);

    if(s->next_expr) {
        expr_codegen(s->next_expr);
        scratch_free(s->next_expr->reg);
    }
    printf("JMP %s\n", label_name(top_label) );
    printf("%s:\n", label_name(done_label) );
}

int label_create()
{
    int l = label_count;
    label_count += 1;
    return l;
}

char *label_name(int i)
{
    char *label = malloc(6 * sizeof(char) );
    sprintf(label, ".L%d", i);
    return label;
}

void expr_codegen(struct expr *e)
{
    if(!e) return;
    switch (e->kind)  {
        case EXPR_INT:
        case EXPR_BOOL:
        case EXPR_CHAR:
            
            e->reg = scratch_alloc();
            printf("MOVQ $%d, %s\n", e->literal_value, scratch_name(e->reg) );
            break;
        case EXPR_STRING: {
            e->reg = scratch_alloc();
            int s_lab = label_create();
            printf("\n.data\n%s: .string \"%s\"\n\n.text\n", 
                    label_name(s_lab), print_string(e->string_literal));
            printf("LEA %s, %s\n", label_name(s_lab), scratch_name(e->reg) );
            break;
        }
        case EXPR_IDENT:
            e->reg = scratch_alloc();
            if(e->symbol->type->kind == TYPE_ARRAY && e->symbol->kind == SYMBOL_GLOBAL) {
                printf("LEA %s, %s\n", symbol_codegen(e->symbol), scratch_name(e->reg) );
            } else {
                printf("MOVQ %s, %s\n", symbol_codegen(e->symbol), scratch_name(e->reg));
            }
            break;
        case EXPR_ARR_START:
            array_start_codegen(e);
            break;
        case EXPR_TERN: {
            expr_codegen(e->left);
            expr_codegen(e->mid);
            expr_codegen(e->right);
            printf("CMP $0, %s\n", scratch_name(e->left->reg) );
            int f_lab = label_create();
            printf("JE %s\n", label_name(f_lab) );
            printf("MOVQ %s, %s\n", scratch_name(e->mid->reg), scratch_name(e->left->reg) );
            int end_lab = label_create();
            printf("JMP %s\n", label_name(end_lab) );
            printf("%s:\nOVQ %s, %s\n", label_name(f_lab), scratch_name(e->right->reg), 
                        scratch_name(e->left->reg) );
            printf("%s:\n", label_name(end_lab) );

            scratch_free(e->right->reg);
            scratch_free(e->mid->reg);
            e->reg = e->left->reg;
            break;
        }
        case EXPR_AND:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("ANDQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg) );
            
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_OR:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("ORQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
            
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_GT:
            comparison_codegen(e, "JG");
            break;
        case EXPR_GE:
            comparison_codegen(e, "JGE");
            break;
        case EXPR_LT:
            comparison_codegen(e, "JL");
            break;
        case EXPR_LE:
            comparison_codegen(e, "JLE");
            break;
        case EXPR_EE:
            if(expr_typecheck(e->left)->kind == TYPE_STRING) {
                struct expr *efunc = expr_create_func("string_compare", 
                        expr_create_args(e->left, expr_create(EXPR_ARG, e->right, NULL) ) );
                expr_codegen(efunc);
                e->reg = efunc->reg;
            } else {
                comparison_codegen(e, "JE");
            }
            break;
        case EXPR_NE:
            comparison_codegen(e, "JNE");
            break;
        case EXPR_ADD:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("ADDQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
            
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_SUB:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("SUBQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->left->reg));
            
            e->reg = e->left->reg;
            scratch_free(e->right->reg);
            break;
        case EXPR_MUL:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("MOVQ %s, %%rax\n", scratch_name(e->left->reg) );
            printf("IMULQ %s\n", scratch_name(e->right->reg));
            printf("MOVQ %%rax, %s\n", scratch_name(e->right->reg));
            
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_DIV:
        case EXPR_REM:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("MOVQ %s, %%rax\n", scratch_name(e->left->reg));
            printf("CQO\n");
            printf("IDIVQ %s\n", scratch_name(e->right->reg));
            printf("MOVQ %%rdx, %s\n", scratch_name(e->right->reg));
            
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_EXP: {
            struct expr *efunc = expr_create_func("integer_power", 
                    expr_create_args(e->left, expr_create(EXPR_ARG, e->right, NULL) ) );
            expr_codegen(efunc);
            
            e->reg = efunc->reg;
            break;
        }
        case EXPR_EQ:
            assignment_codegen(e);
            break;
        case EXPR_NEG:
            expr_codegen(e->right);
            printf("NEGQ %s\n", scratch_name(e->right->reg) );
            
            e->reg = e->right->reg;
            break;
        case EXPR_NOT:
            printf("MOVQ $0, %%rax\n");
            expr_codegen(e->right);
            printf("CMP $0, %s\n", scratch_name(e->right->reg) );
            printf("SETZ %%al\n");
            printf("MOVQ %%rax, %s\n", scratch_name(e->right->reg) );
            
            e->reg = e->right->reg;
            break;
        case EXPR_INC:
            expr_codegen(e->left);
            e->reg = scratch_alloc();
            printf("MOVQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->reg) );
            printf("INCQ %s\n", scratch_name(e->left->reg));
            printf("MOVQ %s, %s\n", scratch_name(e->left->reg), symbol_codegen(e->left->symbol) );
            
            scratch_free(e->left->reg);
            break;
        case EXPR_DEC:
            expr_codegen(e->left);
            e->reg = scratch_alloc();
            printf("MOVQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->reg));
            printf("DECQ %s\n", scratch_name(e->left->reg));
            printf("MOVQ %s, %s\n", scratch_name(e->left->reg), symbol_codegen(e->left->symbol));
            
            scratch_free(e->left->reg);
            break;
        case EXPR_FUNC:
            func_codegen(e);
            break;
    }
}

void comparison_codegen(struct expr *e, char *type)
{
    expr_codegen(e->left);
    expr_codegen(e->right);

    printf("CMPQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->left->reg) );
    int t_lab = label_create();
    printf("%s %s\n", type, label_name(t_lab) );
    printf("MOVQ $0, %s\n", scratch_name(e->right->reg) );

    int end_lab = label_create();
    printf("JMP %s\n", label_name(end_lab) );
    printf("%s:\nMOVQ $1, %s\n", label_name(t_lab), scratch_name(e->right->reg) );
    printf("%s:\n", label_name(end_lab) );

    e->reg = e->right->reg;
    scratch_free(e->left->reg);
}

void func_codegen(struct expr *e)
{
    struct expr *e1 = e->left;
    struct expr *e2 = e->mid;
    e->reg = scratch_alloc();
    struct expr *e3 = e2;
    int count = 0;
    while(e3) {
        expr_codegen(e3->left);
        e3 = e3->mid;
        count++;
    }

    char *aregs[6] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9" };
    count = 0;
    e3 = e2;
    while(e3 && count < 6) {
        struct expr *arg = e3->left;
        printf("MOVQ %s, %s\n", scratch_name(arg->reg), aregs[count] );
        scratch_free(arg->reg);
        e3 = e3->mid;
        count++;
    }

    printf("PUSHQ %%r10\n");
    printf("PUSHQ %%r11\n");
    printf("CALL %s\n", e->left->name);
    printf("POPQ %%r11\n");
    printf("POPQ %%r10\n");
    printf("MOVQ %%rax, %s\n", scratch_name(e->reg) );
}

void array_start_codegen(struct expr *e)
{
    array_start_address_codegen(e);
    printf("MOVQ (%s), %s\n", scratch_name(e->reg), scratch_name(e->reg) );
}

void array_start_address_codegen(struct expr *e)
{
    struct expr *name = e->left;
    expr_codegen(name);
    struct expr *i = e->mid;

    struct expr *offset = expr_create(EXPR_MUL, i->left, expr_create_integer_literal(8) );
    expr_codegen(offset);
    printf("ADDQ %s, %s\n", scratch_name(offset->reg), scratch_name(name->reg) );
    
    scratch_free(offset->reg);
    e->reg = name->reg;
    scratch_free(name->reg);
}

void assignment_codegen(struct expr *e)
{
    e->reg = scratch_alloc();
    expr_codegen(e->right);
    if(e->left->kind != EXPR_ARR_START) {
        printf("MOVQ %s, %s\n", scratch_name(e->right->reg), symbol_codegen(e->left->symbol) );
        printf("MOVQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->reg) );
    } else {
        array_start_address_codegen(e->left);
        printf("MOVQ %s, (%s)\n", scratch_name(e->right->reg), scratch_name(e->left->reg) );
        printf("MOVQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->reg) );
    }

    scratch_free(e->left->reg);
    scratch_free(e->right->reg);
}

char *symbol_codegen(struct symbol *s)
{
    char *c = malloc(10 * sizeof(char) );
    switch(s->kind) {
        case SYMBOL_LOCAL:
            sprintf(c, "%d(%%rbp)", (s->wlocals + 1 + num_args) * -8);
            return c;
        case SYMBOL_GLOBAL:
            return s->name;
        case SYMBOL_PARAM:
            sprintf(c, "%d(%%rbp)", (s->wparams + 1) * -8);
            return c;
    }
    return NULL;
}

char *scratch_name(int reg)
{
    char* name = malloc(6 * sizeof(char) );
    if(reg != 6) {
        sprintf(name, "%%r1%d", reg);
    } else {
        sprintf(name, "%%rbx");
    }
    return name;
}

int scratch_alloc()
{
    int count = 0;
    while(scratches[count] != 0 && count < 6) {
        count++;
    }

    if(count != 6) {
        scratches[count] = 1;
        return count;
    } else {
        fprintf(stderr, "error: no remaining registers\n");
        return -1;
    }
}

void scratch_free(int reg)
{
    scratches[reg] = 0;
}