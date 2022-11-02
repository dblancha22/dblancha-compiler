#include "stmt.h"
#include "expr.h"
#include <stdlib.h>

struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next )
{
    struct stmt *s = calloc(1, sizeof(struct stmt) );
    s->kind = kind;
    s->decl = decl;
    s->init_expr = init_expr;
    s->expr = expr;
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = next;

    return s;
}

struct stmt *stmt_create_list(struct stmt *curr, struct stmt *next)
{
    curr->next = next;
    return curr;
}

struct stmt *stmt_create_print(struct expr *e)
{
    struct stmt *s = stmt_create(STMT_PRINT, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    struct expr *e1 = expr_create(EXPR_LIST, NULL, NULL);
    
    e1->next = e;
    s->expr = e1;
    return s;
}

void stmt_print(struct stmt *s, int indent)
{
    stmt_print_val(s, indent);
}

void stmt_print_val(struct stmt *s, int indent) {
    char *indenter = get_indenter(indent);

    switch(s->kind) {
        case STMT_DECL:
            printf("%s", indenter);
            decl_print(s->decl);
            printf("\n");
            break;
        case STMT_EXPR:
            printf("%s", indenter);
            expr_print(NULL, s->expr);
            printf(";\n");
            break;
        case STMT_IF_ELSE:
            printf("%s", indenter);
            printf("if (");
            expr_print(NULL, s->expr);
            printf(")\n");
            stmt_print(s->body, indent + get_indent_num(s->body));

            if (s->else_body)
            {
                printf("%selse\n", indenter);
                stmt_print(s->else_body, indent + get_indent_num(s->body));
            }
            break;
        case STMT_FOR:
            printf("%s", indenter);
            printf("for (");
            expr_print(s->init_expr, NULL);
            printf("; ");
            expr_print(s->expr, NULL);
            printf("; ");
            expr_print(s->next_expr, NULL);
            printf(")\n");
            stmt_print(s->body, indent + get_indent_num(s->body));
            break;
        case STMT_PRINT:
            printf("%sprint ", indenter);
            expr_print_curr(s->expr);
            printf(";\n");
            break;
        case STMT_RETURN:
            printf("%sreturn ", indenter);
            expr_print(s->expr, NULL);
            printf(";\n");
            break;
        case STMT_BLOCK:
            printf("%s{\n", indenter);
            stmt_print_list(s->body, indent + 1);
            printf("%s}\n", indenter);
            break;
        case STMT_LIST:
            stmt_print_list(s->body, indent);
            break;
    }
}

char * get_indenter(int indent) 
{
    if(indent <= 0) return "";

    int i_len = indent * 4;
    char *indenter = malloc(sizeof(char) * i_len);
    int i;
    for(i = 0; i < i_len; i++) {
        indenter[i] = ' ';
    }
    indenter[i] = '\0';
    return indenter;
}

int get_indent_num(struct stmt* s) 
{
    if(s->kind == STMT_BLOCK) return 0;
    return 1;
}

void stmt_print_list(struct stmt *s, int indent)
{
    if(!s) return;

    struct stmt *s2 = s;
    while(s2->next) {
        stmt_print(s2, indent);
        s2 = s2->next;
    }
    stmt_print(s2, indent);
}