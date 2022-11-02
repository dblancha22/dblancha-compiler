
#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include <stdio.h>

struct decl {
	char *name;
	struct type *type;
	struct expr *value;
	struct stmt *code;
	struct symbol *symbol;
	struct decl *next;
};

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next );
struct decl *decl_create_func(char *name, struct type *type, struct stmt *code);
struct decl *decl_create_list(struct decl *curr, struct decl *next); 

void decl_print(struct decl *d);
void decl_print_list(struct decl *d);

#endif


