#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"


struct expr * expr_create( expr_t kind, struct expr *left, 
                                struct expr *right ) 
{
    struct expr* exs = malloc( sizeof(struct expr) );

    exs->kind = kind;
    exs->left = left;
    exs->right = right;

    return exs;
}

struct expr * expr_create_integer_literal( int c )
{
    struct expr* exs = expr_create(EXPR_INT, NULL, NULL);
    exs->literal_value = c;
    return exs;
}

struct expr * expr_create_boolean_literal( const char *c )
{
    struct expr* exs = expr_create(EXPR_BOOL, NULL, NULL);
    if(strcmp(c, "true") ) {
        exs->literal_value = 1;
    } else {
        exs->literal_value = 0;
    }
    return exs;
}

struct expr * expr_create_char_literal( char c )
{
    struct expr* exs = expr_create(EXPR_CHAR, NULL, NULL);
    exs->literal_value = c;
    return exs;
}

struct expr * expr_create_string_literal( const char *str )
{
    struct expr* exs = expr_create(EXPR_STRING, NULL, NULL);
    exs->string_literal = str;
    return exs;
}

struct expr * expr_create_name( const char *n )
{
    struct expr* exs = expr_create(EXPR_IDENT, NULL, NULL);
    exs->name = n;
    return exs;
}

struct expr * expr_create_tern( struct expr *left, struct expr *mid, struct expr *right )
{
    struct expr* exs = malloc( sizeof(struct expr) );

    exs->kind = EXPR_TERN;
    exs->mid = mid;
    exs->left = left;
    exs->right = right;

    return exs;
}

struct expr * expr_create_list( struct expr *curr, struct expr *next) {
    struct expr *e1 = expr_create(EXPR_LIST, curr, NULL);
    e1->mid = next;
    return e1;
}

void print_list(struct expr *e) 
{
    if(!e || !(e->next) ) return;

    struct expr *curr = e->next;
    while(curr->next) {
        expr_print(e, curr);
        printf(", ");
        curr = curr->next;
    }
    expr_print(e, curr);
}

struct expr * expr_create_func(char *func, struct expr *args) {
    struct expr *name = expr_create_name(func);
    // struct expr *e1 = expr_create(EXPR_LIST, NULL, NULL);
    // e1->next = args;
    struct expr *e2 = expr_create(EXPR_FUNC, name, NULL);
    e2->mid = args;
    return e2;
}

struct expr * expr_create_args(struct expr *curr, struct expr *next)
{
    struct expr *e1 = expr_create(EXPR_ARG, curr, NULL);
    e1->mid = next;
    return e1;
}

struct expr * expr_create_arr_start(char *name, struct expr *bracks) 
{
    struct expr *name1 = expr_create_name(name);
    struct expr *e1 = expr_create(EXPR_ARR_START, name1, NULL);

    e1->mid = bracks;
    return e1;
}

struct expr * expr_create_indeces(struct expr *curr, struct expr *next) 
{
    struct expr *e1 = expr_create(EXPR_INDEX, curr, NULL);
    e1->mid = next;
    return e1;
}

struct expr * expr_create_arr_literal(struct expr *next)
{
    struct expr* e1 = expr_create(EXPR_ARR, NULL, NULL);
    e1->mid = next;
    return e1;
}

char parse_char(const char *str)
{
    char c;
    const char *s1 = str + 1;
    if(*s1 == '\\') {
        const char *next = s1 + 1;
        if(*next == 'n') {
            c = '\n';
        } else if(*next == '0') {
            c = '\0';
        } else {
            c = *next;
        }
    } else {
        c = *s1;
    }
    return c;
}

char* parse_string(const char *str)
{
    char *c = malloc(sizeof(char) * strlen(str) );
    int i = 0;
    const char* curr = str + 1;
    while(curr < str + strlen(str) - 1) {
        if(*curr == '\\') {
            const char* next = curr + 1;
            if(*next == 'n') {
                c[i] = '\n';
            } else if(*next == '0') {
                c[i] = '\0';
            } else {
                c[i] = *next;
            }
            curr += 2;
        } else {
            c[i] = *curr;
            curr++;
        }
        i++;
    }

    return c;
}

void expr_print( struct expr *p, struct expr *e )
{
    if(!e) return;

    if(parens(p, e) ) printf("(");

    expr_print(e, e->left);
    expr_print_curr(e);
    expr_print(e, e->right);

    if(parens(p, e) ) printf(")");

}

void expr_print_curr(struct expr *e)
{
    switch(e->kind) {
        case EXPR_ADD:
            printf(" + ");
            break;
        case EXPR_SUB:
            printf(" - ");
            break;
        case EXPR_MUL:
            printf(" * ");
            break;
        case EXPR_DIV:
            printf(" / ");
            break;
        case EXPR_EQ:
            printf(" = ");
            break;
        case EXPR_OR:
            printf(" || ");
            break;
        case EXPR_AND:
            printf(" && ");
            break;
        case EXPR_GT:
            printf(" > ");
            break;
        case EXPR_GE:
            printf(" >= ");
            break;
        case EXPR_LT:
            printf(" < ");
            break;
        case EXPR_LE:
            printf(" <= ");
            break;
        case EXPR_EE:
            printf(" == ");
            break;
        case EXPR_NE:
            printf(" != ");
            break;
        case EXPR_REM:
            printf(" %% ");
            break;
        case EXPR_EXP:
            printf(" ^ ");
            break;
        case EXPR_NEG:
            printf(" -");
            break;
        case EXPR_NOT:
            printf(" !");
            break;
        case EXPR_INC:
            printf(" ++ ");
            break;
        case EXPR_DEC:
            printf(" -- ");
            break;
        case EXPR_INT:
            printf("%d", e->literal_value);
            break;
        case EXPR_BOOL:
            if(e->literal_value == 1) {
                printf(" true ");
            } else {
                printf(" false ");
            }
            break;
        case EXPR_CHAR: {
            char* new_char = print_char(e->literal_value);
            printf("'%s'", new_char);
            break;
        }
        case EXPR_STRING: {
            char* new_string= print_string(e->string_literal);
            printf("\"%s\"", new_string);
            break;
        }
        case EXPR_IDENT:
            printf("%s", e->name);
            break;
        case EXPR_TERN:
            printf(" ? ");
            expr_print(e, e->mid);
            printf(" : ");
            break;
        case EXPR_LIST:
            print_list(e);
            break;
        case EXPR_FUNC:
            printf("(");
            expr_print(NULL, e->mid);
            printf(")");
            break;
        case EXPR_ARG:
            if(e->mid) {
                printf(", ");
                expr_print(NULL, e->mid);
            }
            break;
        case EXPR_ARR:
            printf("{");
            print_list(e->mid);
            printf("}");
            break;
        case EXPR_ARR_START:
            print_arr_start(e->mid);
            break;
    }
}

char* print_char(char str) 
{
    char* new_str = &str;
    if(str == '\n') {
        new_str = "\\n";
    } else if(str == '\0') {
        new_str = "\\0";
    } else {
        new_str = malloc(sizeof(char) * 2);
        new_str[0] = str;
        new_str[1] = '\0';
    }
    return new_str;
}

char* print_string(const char* str)
{
    char *c = malloc(sizeof(char) * 2 * strlen(str) );
    int i = 0;
    const char* curr = str;
    while(curr < str + strlen(str) ) {
        if(*curr == '\n') {
            c[i] = '\\';
            c[i+1] = 'n';
            i += 2;
        } else if(*curr == '\0') {
            c[i] = '\\';
            c[i+1] = '0';
            i += 2;
        } else if(*curr == '\\') {
            c[i] = '\\';
            c[i+1] = '\\';
            i += 2;
        } else {
            c[i] = *curr;
            i++;
        }
        curr++;
    }
    c[i] = '\0';
    
    return c;
}

void print_arr_start(struct expr *e) 
{
    if(!e || !(e->next) ) return;

    struct expr *e1 = e->next;
    while(e1) {
        printf("[");
        expr_print(e, e1);
        printf("]");
        e1 = e1->next;
    }
}

int expr_oop(struct expr* e) 
{
    if(!e) return -1;
    
    switch(e->kind) {
        case EXPR_EQ:
        case EXPR_TERN:
            return 0;
        case EXPR_OR:
            return 1;
        case EXPR_AND:
            return 2;
        case EXPR_GT:
	    case EXPR_GE:
	    case EXPR_LT:
	    case EXPR_LE:
	    case EXPR_EE:
	    case EXPR_NE:
            return 3;
        case EXPR_ADD:
        case EXPR_SUB:
            return 4;
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_REM:
            return 5;
        case EXPR_EXP:
            return 6;
        case EXPR_NEG:
        case EXPR_NOT:
            return 7;
        case EXPR_INC:
        case EXPR_DEC:
            return 8;
    }
    return 0;
}

int parens(struct expr* p, struct expr* c)
{
    int pr = expr_oop(p);
    int er = expr_oop(c);
    if(pr > 0 && er> 0 && pr >= er) {
        return 1;
    }
    return 0;
}