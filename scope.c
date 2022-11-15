#include "scope.h"
#include "hash_table.h"
#include <stdlib.h>

struct scope * scope_stack;
int r_err = 0;

void scope_enter()
{
    struct scope *new_scope = malloc(sizeof(struct scope) );

    new_scope->dist = 0;
    new_scope->hash = hash_table_create(0,0);
    new_scope->next = scope_stack;

    scope_stack = new_scope;
}

void scope_exit()
{
    struct scope *remove = scope_stack;
    scope_stack = scope_stack->next;
    hash_table_delete(remove->hash);
    free(remove);
}

void scope_bind(const char *name, struct symbol *s)
{
    s->which = scope_stack->dist;
    if(s->type->kind != TYPE_FUNCTION && hash_table_insert(scope_stack->hash, name, s) != 1) {
        printf("resolve error: %s is already defined in this scope\n", s->name);
        r_err = 1;
    } else if (s->type->kind == TYPE_FUNCTION) {
        struct symbol *s1 = hash_table_lookup(scope_stack->hash, name);
        if(s1 && s1->prototype == 0){
            printf("resolve error: %s is already defined in this scope\n", s->name);
            r_err = 1;
        } else if(s1 && s1->prototype == 1 && s->prototype == 0) {
            if(!type_equals(s1->type, s->type) ) {
                printf("resolve error: %s has the wrong parameters\n", s->name);
                r_err = 1;
            }
            s1->prototype = 0;
        } else if (!s1) {
            hash_table_insert(scope_stack->hash, name, s);
        }
    }


    scope_stack->dist += 1;
}

int scope_level()
{
    if(scope_stack->next) return 1;
    return 0;
}

struct symbol *scope_lookup(const char *name)
{
    struct scope *curr = scope_stack;
    while(curr) {
        struct symbol *s = hash_table_lookup(curr->hash, name);
        if(s) {
            if(s->kind == SYMBOL_GLOBAL) {
                printf("%s resolves to global %s\n", name, s->name);
            } else if(s->kind == SYMBOL_LOCAL) {
                printf("%s resolves to local %d\n", name, s->which);
            }else if(s->kind = SYMBOL_PARAM) {
                printf("%s resolves to global %d\n", name, s->which);
            }

            return s;
        }
        curr = curr->next;
    }
    printf("resolve error: %s is not defined\n", name);
    r_err = 1;

    return NULL;
}
