#include "type.h"
#include "expr.h"
#include <stdlib.h>

struct type *type_create(type_t kind, struct type *subtype, struct param_list *params)
{
    struct type *t = calloc(1, sizeof(struct type));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    t->expr = NULL;

    return t;
}

struct type *type_create_func(type_t kind, struct param_list *params)
{
    struct type *t1 = type_create(kind, NULL, NULL);
    struct type *t2 = type_create(TYPE_FUNCTION, t1, params);
    return t2;
}

struct type *type_create_arr(struct expr *e, struct type *t)
{
    struct type *t1 = type_create(TYPE_ARRAY, t, NULL);
    t1->expr = e;
    return t1;
}

int type_equals(struct type *t1, struct type *t2) 
{
    if(!t1 && !t2) return 1;
    if(!t1 || !t2) return 0;
    
    if(t1->kind == t2->kind && type_equals(t1->subtype, t2->subtype) ) {
        if(t1->kind == TYPE_ARRAY && t1->expr && t2->expr && t1->expr->literal_value != t2->expr->literal_value && param_list_equals(t1->params, t2->params) ) {
            return 0;
        }
        return 1;
    }
    return 0;
}

struct type * type_copy(struct type *t)
{
    if(!t) return NULL;
    struct type *new_type = type_create(t->kind, type_copy(t->subtype), param_list_copy(t->params) );
    new_type->expr = t->expr;
    return new_type;
}

void type_print(struct type *t)
{
    if(!t) return;

    switch(t->kind) {
    case TYPE_VOID:
        printf("void");
        break;
    case TYPE_BOOLEAN:
        printf("boolean");
        break;
    case TYPE_CHARACTER:
        printf("char");
        break;
    case TYPE_INTEGER:
        printf("integer");
        break;
    case TYPE_STRING:
        printf("string");
        break;
    case TYPE_ARRAY:
        printf("array[");
        if (t->expr)
            expr_print(t->expr, NULL);
        printf("] ");
        type_print(t->subtype);
        break;
    case TYPE_FUNCTION:
        printf("function ");
        type_print(t->subtype);
        param_list_print(t->params);
        break;
    case TYPE_AUTO:
        printf("auto");
        break;
    }

}