
#ifndef STMT_H
#define STMT_H

#include "decl.h"

typedef enum {
	STMT_DECL,
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_FOR,
	STMT_PRINT,
	STMT_RETURN,
	STMT_BLOCK,
	STMT_LIST
} stmt_t;

struct stmt {
	stmt_t kind;
	struct decl *decl;
	struct expr *init_expr;
	struct expr *expr;
	struct expr *next_expr;
	struct stmt *body;
	struct stmt *else_body;
	struct stmt *next;
};

struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next );
struct stmt * stmt_create_list(struct stmt *curr, struct stmt *next);
struct stmt * stmt_create_print(struct expr *e);

void stmt_print( struct stmt *s, int indent );
void stmt_print_val(struct stmt *s, int indent);
char *get_indenter(int indent);
int get_indent_num(struct stmt *s);
void stmt_print_list(struct stmt *s, int indent);

#endif
