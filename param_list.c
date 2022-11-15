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

struct param_list *param_list_copy(struct param_list *p)
{
    if(!p) return NULL;
    struct param_list *curr = p;
    struct param_list *p1 = param_list_create(curr->name, type_copy(curr->type), NULL);
    struct param_list *p2 = p1;
    curr = curr->next;

    while(curr) {
        p2 = param_list_create(curr->name, type_copy(curr->type), NULL);
        p2 = p2->next;
        curr = curr->next;
    }
    return p1;
}

int param_list_equals(struct param_list *p1, struct param_list *p2) 
{
    struct param_list *curr1 = p1;
    struct param_list *curr2 = p2;
    while(curr1 && curr2) {
        if(!type_equals(curr1->type, curr2->type) ) {
            return 0;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if( (!curr1 && curr2) || (curr1 && !curr2) ) {
        return 0;
    }
    return 1;
}