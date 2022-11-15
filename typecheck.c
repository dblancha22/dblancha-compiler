#include "typecheck.h"
#include "type.h"

int err = 0;

struct type *expr_typecheck(struct expr *e)
{
    if(!e) 
        return NULL;

    struct type *l_type = expr_typecheck(e->left);
    struct type *m_type = expr_typecheck(e->mid);
    struct type *r_type = expr_typecheck(e->right);
    struct type *check;

    switch(e->kind) {
        case EXPR_INT:
            check = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_STRING:
            check = type_create(TYPE_STRING, NULL, NULL);
            break;
        case EXPR_CHAR:
            check = type_create(TYPE_CHARACTER, NULL, NULL);
            break;
        case EXPR_BOOL:
            check = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_IDENT:
            check = type_copy(e->symbol->type);
            break;
        case EXPR_EQ:
            if(e->left->kind != EXPR_IDENT && e->left->kind != EXPR_ARR_START) {
                printf("type error: can't assign a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(") to a constant");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(")\n");
                err = 1;
            }
            if (!type_equals(l_type, r_type) ) {
                printf("type error: can't assign a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(") to a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(")\n");
                err = 1;
            }
            check = type_copy(l_type);
            break;
        case EXPR_TERN:
            if(l_type->kind != TYPE_BOOLEAN) {
                printf("type error: can't use a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") in a ternary expression (must be a boolean)\n");
                err = 1;
            }
            if(!type_equals(m_type, r_type) ) {
                printf("type error: can't return different types ");
                type_print(m_type);
                printf(" (");
                expr_print(e->mid, NULL);
                printf(") and ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(") in a ternary expression\n");
                err = 1;
            }
            check = type_copy(m_type);
            break;
        case EXPR_AND:
            if(l_type->kind != TYPE_BOOLEAN || r_type->kind != TYPE_BOOLEAN) {
                printf("type error: can't AND a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") and a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(") (both must be booleans)\n ");
                err = 1;
            }
            check = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_OR:
            if (l_type->kind != TYPE_BOOLEAN || r_type->kind != TYPE_BOOLEAN)
            {
                printf("type error: can't OR a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") and a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(") (both must be booleans)\n ");
                err = 1;
            }
            check = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_GT:
        case EXPR_GE:
        case EXPR_LT:
        case EXPR_LE:
            if (l_type->kind != TYPE_INTEGER || r_type->kind != TYPE_INTEGER)
            {
                printf("type error: can't compare a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") to a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(") (both must be integers)\n ");
                err = 1;
            }
            check = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_EE:
        case EXPR_NE:
            if (l_type->kind == TYPE_ARRAY || l_type->kind == TYPE_FUNCTION || l_type->kind == TYPE_VOID)
            {
                printf("type error: can't use a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") in an equality test\n");
                err = 1;
            }
            if (r_type->kind == TYPE_ARRAY || r_type->kind == TYPE_FUNCTION || r_type->kind == TYPE_VOID)
            {
                printf("type error: can't use a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(") in an equality test\n");
                err = 1;
            }
            if(!type_equals(l_type, r_type) ) {
                printf("type error: can't compare a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") to a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(") (both must be same type)\n ");
                err = 1;
            }
            check = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_ADD:
            if (l_type->kind != TYPE_INTEGER || r_type->kind != TYPE_INTEGER)
            {
                printf("type error: can't add a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") to a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(")\n");
                err = 1;
            }
            check = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_SUB:
            if (l_type->kind != TYPE_INTEGER || r_type->kind != TYPE_INTEGER)
            {
                printf("type error: can't subtract a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") from a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(")\n");
                err = 1;
            }
            check = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_MUL:
            if (l_type->kind != TYPE_INTEGER || r_type->kind != TYPE_INTEGER)
            {
                printf("type error: can't multiply a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") with a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(")\n");
                err = 1;
            }
            check = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_DIV:
            if (l_type->kind != TYPE_INTEGER || r_type->kind != TYPE_INTEGER)
            {
                printf("type error: can't divide a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") from a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(")\n");
                err = 1;
            }
            check = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_REM:
            if (l_type->kind != TYPE_INTEGER || r_type->kind != TYPE_INTEGER)
            {
                printf("type error: can't mod a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") with a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(")\n");
                err = 1;
            }
            check = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_EXP:
            if (l_type->kind != TYPE_INTEGER || r_type->kind != TYPE_INTEGER)
            {
                printf("type error: can't exponentiate a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") with a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(")\n");
                err = 1;
            }
            check = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_NEG:
            if(r_type->kind != TYPE_INTEGER) {
                printf("type error: can't negate a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(") (must be integer)\n");
                err = 1;
            }
            check = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_NOT:
            if (r_type->kind != TYPE_BOOLEAN)
            {
                printf("type error: can't negate a ");
                type_print(r_type);
                printf(" (");
                expr_print(e->right, NULL);
                printf(") (must be boolean)\n");
                err = 1;
            }
            check = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_INC:
            if (l_type->kind != TYPE_INTEGER)
            {
                printf("type error: can't increment a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") (must be integer)\n");
                err = 1;
            }
            check = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_DEC:
            if (l_type->kind != TYPE_INTEGER)
            {
                printf("type error: can't increment a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(") (must be integer)\n");
                err = 1;
            }
            check = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_FUNC: {
            struct param_list *params = e->left->symbol->type->params;
            struct expr *args = e->mid;
            param_list_typecheck(e->left->name, params, args);
            check = type_copy(e->left->symbol->type->subtype);
            break;
        }
        case EXPR_ARR: {
            struct expr *e1 = e->mid;
            struct type *arr_type = expr_typecheck(e1->left);
            while(e1) {
                struct type *e1_type = expr_typecheck(e1->left);
                if(!type_equals(e1_type, arr_type) ) {
                    type_print(e1_type);
                    printf(" (");
                    expr_print(e1->left, NULL);
                    printf(")\n");
                    err = 1;
                }
                e1 = e1->mid;
            }
            int arr_len = 0;
            e1 = e->mid;
            while(e1) {
                arr_len++;
                e1 = e1->mid;
            }
            check = type_create(TYPE_ARRAY, type_copy(arr_type), NULL);
            check->expr = expr_create_integer_literal(arr_len);
            break;
        }
        case EXPR_ARR_START:
            if (l_type->kind != TYPE_ARRAY)
            {
                printf("type error: can't index a ");
                type_print(l_type);
                printf(" (");
                expr_print(e->left, NULL);
                printf(")\n");
                err = 1;
            }
            check = array_start_typecheck(e->mid, l_type->subtype);
            break;
    }



}

void decl_typecheck(struct decl *d)
{
    if(!d) return;
    if(d->value) {
        struct type *e_type = expr_typecheck(d->value);
        if(!type_equals(d->type, e_type) && d->type->kind != TYPE_AUTO) {
            printf("type error: can't assign a ");
            type_print(e_type);
            printf(" (");
            expr_print(d->value, NULL);
            printf(") to a ");
            type_print(d->type);
            printf("\n");
            err = 1;
        }
        if(d->type->kind == TYPE_ARRAY) {
            struct type *t1 = d->type;
            while(t1->kind = TYPE_ARRAY) {
                if(t1->expr->kind != EXPR_INT) {
                    printf("type error: must use integer in array size declarations, not ");
                    expr_print(t1->expr, NULL);
                    printf("\n");
                    err = 1;
                }
                t1 = t1->subtype;
            }
        }
        if(d->type->kind == TYPE_AUTO) {
            d->type = type_copy(e_type);
            d->symbol->type = type_copy(e_type);
        }
    }
    if(d->code) {
        stmt_typecheck(d->code, d);
        if(d->type->subtype->kind == TYPE_FUNCTION) {
            printf("type error: function is an invalid return type for %s", d->name);
        }
    }
    decl_typecheck(d->next);
}

void stmt_typecheck(struct stmt *s, struct decl *func)
{
    if(!s) return;
    struct type *f_type = func->symbol->type;
    struct type *t1;
    switch(s->kind) {
        case STMT_DECL:
            decl_typecheck(s->decl);
            break;
        case STMT_EXPR:
            expr_typecheck(s->expr);
            break;
        case STMT_BLOCK:
            stmt_typecheck(s->body, func);
            break;
        case STMT_IF_ELSE:
            t1 = expr_typecheck(s->expr);
            if (t1->kind != TYPE_BOOLEAN)
            {
                printf("type error: can't use ");
                type_print(t1);
                printf(" (");
                expr_print(s->expr, NULL);
                printf(") as a condition (must be boolean)");
                err = 1;
            }
            stmt_typecheck(s->body, func);
            stmt_typecheck(s->else_body, func);
            break;
        case STMT_FOR:
            expr_typecheck(s->init_expr);
            expr_typecheck(s->expr);
            expr_typecheck(s->next_expr);
            stmt_typecheck(s->body, func);
            break;
        case STMT_RETURN:
            t1 = expr_typecheck(s->expr);
            if (!t1) {
                t1 = type_create(TYPE_VOID, NULL, NULL);
            }

            if (f_type->subtype->kind == TYPE_AUTO) {
                f_type->subtype = type_copy(t1);
                func->type = type_copy(t1);
            }

            if (!type_equals(f_type->subtype, t1) ) {
                printf("type error: can't return a ");
                type_print(t1);
                printf(" (");
                expr_print(s->expr, NULL);
                printf(") in a function that returns ");
                type_print(f_type->subtype);
                printf("\n");
                err = 1;
            }
            break;
        case STMT_PRINT:
        {
            struct expr *e1 = s->expr;
            while (e1)
            {
                expr_typecheck(e1->left);
                e1 = e1->mid;
            }
        }
        break;
    }
    stmt_typecheck(s->next, func);
}

void param_list_typecheck(const char *f_name, struct param_list *params, struct expr *args)
{
    struct param_list *p1 = params;
    struct expr *e1 = args;
    while (p1 && e1) {
        struct type *t1 = expr_typecheck(e1->left);
        struct type *t2 = p1->type;
        if (!type_equals(t2, t1) ) {
            printf("type error: passing ");
            type_print(t1);
            printf(" (");
            expr_print(e1->left, NULL);
            printf("), ");
            printf("expected ");
            type_print(t2);
            printf(" to %s\n", f_name);
            err = 1;
        }
        p1 = p1->next;
        e1 = e1->mid;
    }
    if (p1 && !e1) {
        printf("type error: not enough arguments passed to %s\n", f_name);
        err = 1;
    } else if (!p1 && e1) {
        printf("type error: too many arguments passed to %s\n", f_name);
        err = 1;
    }
}

struct type *array_start_typecheck(struct expr *indeces, struct type *t)
{
    struct expr *e_index = indeces;
    struct type *t1 = t;
    struct type *t0 = NULL;

    while (e_index && t1) {
        struct type *index_type = expr_typecheck(e_index->left);
        if (index_type->kind != TYPE_INTEGER) {
            printf("type error: can't use a ");
            type_print(index_type);
            printf(" ()");
            expr_print(e_index->left, NULL);
            printf("() ");
            printf("as an array index (must be integer)\n");
            err = 1;
        }
        e_index = e_index->mid;
        t0 = t1;
        t1 = t1->subtype;
    }
    if (!t1 && e_index)
    {
        printf("type error: can't index a ");
        type_print(t0);
        printf("\n");
        err = 1;
    }
    return t0;
}