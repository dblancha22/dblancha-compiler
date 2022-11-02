#include "type.h"
#include "expr.h"
#include <stdlib.h>

struct type *type_create(type_t kind, struct type *subtype, struct param_list *params)
{
    struct type *t = calloc(1, sizeof(struct type));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;

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