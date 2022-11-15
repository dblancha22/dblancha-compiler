#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "expr.h"
#include "decl.h"

struct type * expr_typecheck(struct expr *e);
void decl_typecheck(struct decl *d);
void stmt_typecheck(struct stmt *s, struct decl *func);
void param_list_typecheck(const char *f_name, struct param_list *params, struct expr *args);
struct type *array_start_typecheck(struct expr *indeces, struct type *t);

#endif