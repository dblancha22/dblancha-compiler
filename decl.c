#include "decl.h"
#include <stdlib.h>

struct decl *decl_create(char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next)
{
    struct decl *d = calloc(1, sizeof(struct decl) );
    d->name = name;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;

    return d;
}

struct decl *decl_create_func(char *name, struct type *type, struct stmt *code)
{
    struct stmt *s = stmt_create(STMT_LIST, NULL, NULL, NULL, NULL, code, NULL, NULL);
    struct decl *d = decl_create(name, type, NULL, s, NULL);
    return d;
}

struct decl *decl_create_list(struct decl *curr, struct decl *next)
{
    curr->next = next;
    return curr;
}

void decl_print(struct decl *d)
{
    if(!d) return;

    if(d->type->kind != TYPE_FUNCTION) {
        printf("%s: ", d->name);
        type_print(d->type);

        if(!d->value) {
            printf(";\n");
            return;
        }
        printf(" = ");
        expr_print(NULL, d->value);
        printf(";");
    } else {
        printf("%s: ", d->name);
        type_print(d->type);

        if(!d->code) {
            printf(";");
            return;
        }
        printf(" = {\n");
        stmt_print(d->code, 1);
        printf("\n}");
    }

}

void decl_print_list(struct decl *d) {
    if(!d) return;
    while(d->next) {
        decl_print(d); 
        d = d->next;
        printf("\n\n");
    }
    decl_print(d);
}