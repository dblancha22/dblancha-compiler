#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"

typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_EQ,
	EXPR_OR,
	EXPR_AND,
	EXPR_GT,
	EXPR_GE,
	EXPR_LT,
	EXPR_LE,
	EXPR_EE,
	EXPR_NE,
	EXPR_REM,
	EXPR_EXP,
	EXPR_NEG,
	EXPR_NOT,
	EXPR_INC,
	EXPR_DEC,
	EXPR_INT,
	EXPR_BOOL,
	EXPR_CHAR,
	EXPR_STRING,
	EXPR_IDENT,
	EXPR_TERN,
	EXPR_LIST,
	EXPR_FUNC, 
	EXPR_ARR,
	EXPR_ARR_START
	/* many more kinds of exprs to add here */
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *mid;
	struct expr *right;
	struct expr *next;

	/* used by various leaf exprs */
	const char *name;
	int literal_value;
	const char * string_literal;
	struct symbol *symbol;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );

struct expr * expr_create_name( const char *n );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_boolean_literal( const char *c );
struct expr * expr_create_char_literal( char c );
struct expr * expr_create_string_literal( const char *str );
struct expr * expr_create_tern( struct expr *left, struct expr *mid, struct expr *right );
struct expr * expr_create_list( struct expr *curr, struct expr *next);
struct expr * expr_create_func(char *func, struct expr *args);
struct expr *expr_create_arr_start(char *name, struct expr *bracks);
struct expr * expr_create_arr_literal(struct expr *next);

void expr_print( struct expr *p, struct expr *e );
void expr_print_curr(struct expr *e);
char parse_char(const char *str);
char* parse_string(const char *str);
char* print_char(const char str) ;
char* print_string(const char* str);
void print_list(struct expr *e);
void print_arr_start(struct expr *e);

int expr_oop(struct expr *e);
int parens(struct expr* p, struct expr* c);




#endif
