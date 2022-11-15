#ifndef TYPE_H
#define TYPE_H

#include "param_list.h"

typedef enum {
	TYPE_VOID,
	TYPE_BOOLEAN,
	TYPE_CHARACTER,
	TYPE_INTEGER,
	TYPE_STRING,
	TYPE_ARRAY,
	TYPE_FUNCTION,
	TYPE_AUTO,
} type_t;

struct type {
	type_t kind;
	struct param_list *params;
	struct type *subtype;
	struct expr *expr;
};

struct type * type_create( type_t kind, struct type *subtype, struct param_list *params );
struct type * type_create_func(type_t kind, struct param_list *params);
struct type * type_create_arr(struct expr *e, struct type * t);
void type_print( struct type *t );
int type_equals(struct type *t1, struct type *t2);
struct type *type_copy(struct type *t);

#endif
