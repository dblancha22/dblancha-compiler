#include "param_list.h"
#include <stdlib.h>

struct param_list *param_list_create(char *name, struct type *type, struct param_list *next)
{
    struct param_list *p = calloc(1, sizeof(struct param_list) );
    p->name = name;
    p->type = type;
    p->next = next;

    return p;
}

void param_list_print(struct param_list *a)
{
    if(!a) {
        printf(" ()");
        return;
    }
    printf(" (");
    while(a->next) {
        print_param(a);
        printf(", ");
        a = a->next;
    }
    print_param(a);
    printf(")");
}

void print_param(struct param_list *p)
{
    printf("%s: ", p->name);
    type_print(p->type);
}