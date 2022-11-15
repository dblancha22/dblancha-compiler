#include "scope.h"
#include "hash_table.h"
#include <stdlib.h>

struct scope * scope_stack;

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
    if(hash_table_insert(scope_stack->hash, name, s) == 1) {
        printf("resolve error: %s is already defined in this scope\n", s->name);
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

    return NULL;
}
