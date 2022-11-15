#ifndef RESOLVE_H
#define RESOLVE_H

#include "decl.h"
#include "expr.h"
#include "param_list.h"

void decl_resolve(struct decl *d);
void param_list_resolve(struct param_list *p);
void stmt_resolve(struct stmt *s);
void expr_resolve(struct expr *e);


#endif