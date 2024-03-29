#include "tokens.h"
#include "expr.h"
#include "stmt.h"
#include "type.h"
#include "decl.h"
#include "scope.h"
#include "resolve.h"
#include "typecheck.h"
#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern int yylex();
extern int yyleng;
extern char *yytext;
extern struct decl *root;
extern struct scope *scope_stack;
extern int err;
extern int r_err;

typedef enum yytokentype token_t;

int scan(char* f);
char* escape_chars();
void print_token(token_t t);
int parse(char *f);
int print(char *f);
int resolve(char *f);
int typecheck(char *f);
int codegen(char *inf, char *outf);



int main(int argc, char **argv)
{

    int i;
    for (i = 1; i < argc && argv[i][0] == '-'; i++) {
        if (!strcmp(argv[i], "-scan")) {
            return scan(argv[i+1]); 
        } else if (!strcmp(argv[i], "-parse")) {
            return parse(argv[i+1]);
        } else if (!strcmp(argv[i], "-print")) {
            return print(argv[i+1]);
        } else if (!strcmp(argv[i], "-resolve")) {
            return resolve(argv[i+1]);
        } else if (!strcmp(argv[i], "-typecheck")) {
            return typecheck(argv[i+1]);
        } else if (!strcmp(argv[i], "-codegen")) {
            return codegen(argv[i+1], argv[i+2]);
        }
    }

    return 0;
}

int scan(char* f) {
    if (!f) {
        printf("Missing file.\n");
        return 1;
    }

	yyin = fopen(f,"r");
	if (!yyin) {
		printf("unable to open %s!\n", f);
		return 1;
	}
	while (1) {
		token_t t = yylex();
        switch(t) {
            case STRING_LITERAL:
                if (strlen(yytext) > 255) {
                    printf("scan error: %s is over max string length of 255 (%d)\n", yytext, strlen(yytext));
                    return 1;
                }
                break;
            case TOKEN_EOF:
                return 0;
            case TOKEN_ERROR:
                printf("scan error: %s is not a valid token\n", yytext);
                return 1;
        }

        print_token(t);
	}

    return 0;
}

int parse(char *f) {
    if (!f) {
        printf("Missing file.\n");
        return 1;
    }

	yyin = fopen(f,"r");
	if (!yyin) {
		printf("unable to open %s!\n", f);
		return 1;
	}

    if(yyparse() == 0) {
        printf("Parse successful: \n");
        return 0;
    }

    printf("Parse unsuccessful: %s\n", yytext);
    return 1;
}

int print(char *f) {
    if (!f)
    {
        printf("Missing file.\n");
        return 1;
    }

    yyin = fopen(f, "r");
    if (!yyin)
    {
        printf("unable to open %s!\n", f);
        return 1;
    }

    if (yyparse() != 0)
    {
        return 1;
    }
    
    fprintf(stderr, "%d\n", root->code->next->expr->left->kind);
    decl_print_list(root);
    fprintf(stderr, "finished codegen\n");
    return 0;

}

int resolve(char *f) 
{
    if(!f) {
        printf("Missing file.\n");
        return 1;
    } 

    yyin = fopen(f, "r");
    if(!yyin) {
        printf("unable to open %s!\n", f);
        return 1;
    }

    if (yyparse() != 0) {
        printf("parse failed\n");
        return 1;
    }

    scope_enter();
    decl_resolve(root);
    scope_exit();


    return r_err;
}

int typecheck(char *f)
{
    if (resolve(f) == 1)
    {
        return 1;
    }

    decl_typecheck(root);

    return err;


}

int codegen(char *inf, char *outf)
{
    if(!outf) {
        printf("need an output file\n");
        return 1;
    }

    if(typecheck(inf) == 1) {
        return 1;
    }
    freopen(outf, "w", stdout);
    decl_codegen(root, 2);

    return 0;
}

void print_token(token_t t) {
    switch(t) {
        case TOKEN_EOF:
            printf("TOKEN_EOF %s\n", yytext);
            break;
        case ARRAY:
            printf("ARRAY %s\n", yytext);
            break;
        case AUTO:
            printf("AUTO %s\n", yytext);
            break;
        case BOOLEAN:
            printf("BOOLEAN %s\n", yytext);
            break;
        case CHAR:
            printf("CHAR %s\n", yytext);
            break;
        case ELSE:
            printf("ELSE %s\n", yytext);
            break;
        case FALSE:
            printf("FALSE %s\n", yytext);
            break;
        case FOR:
            printf("FOR %s\n", yytext);
            break;
        case FUNCTION:
            printf("FUNCTION %s\n", yytext);
            break;
        case IF:
            printf("IF %s\n", yytext);
            break;
        case INTEGER:
            printf("INTEGER %s\n", yytext);
            break;
        case PRINT:
            printf("PRINT %s\n", yytext);
            break;
        case RETURN:
            printf("RETURN %s\n", yytext);
            break;
        case STRING:
            printf("STRING %s\n", yytext);
            break;
        case TRUE:
            printf("TRUE %s\n", yytext);
            break;
        case VOID:
            printf("VOID %s\n", yytext);
            break;
        case WHILE:
            printf("WHILE %s\n", yytext);
            break;
        case SEMICOLON:
            printf("SEMICOLON %s\n", yytext);
            break;
        case COLON:
            printf("COLON %s\n", yytext);
            break;
        case QUESTION:
            printf("QUESTION %s\n", yytext);
            break;
        case INTEGER_LITERAL:
            printf("INTEGER_LITERAL %s\n", yytext);
            break;
        case BOOLEAN_LITERAL:
            printf("BOOLEAN_LITERAL %s\n", yytext);
            break;
        case CHAR_LITERAL: {
            char* s = escape_chars();
            printf("CHAR_LITERAL %s\n", yytext);
            free(s);
            break;
        }
        case STRING_LITERAL: {
            char* s = escape_chars();
            printf("STRING_LITERAL %s\n", s);
            free(s);
            break;
         }
        case IDENTIFIER:
            printf("IDENTIFIER %s\n", yytext);
            break;
        case TOKEN_ERROR:
            printf("TOKEN_ERROR %s\n", yytext);
            break;
        case REMAINDER:
            printf("REMAINDER %s\n", yytext);
            break;
        case EXP:
            printf("EXP %s\n", yytext);
            break;
        case EQUALS:
            printf("EQUALS %s\n", yytext);
            break;
        case GT:
            printf("GT %s\n", yytext);
            break;
        case GE:
            printf("GE %s\n", yytext);
            break;
        case LT:
            printf("LT %s\n", yytext);
            break;
        case LE:
            printf("LE %s\n", yytext);
            break;
        case EE:
            printf("EE %s\n", yytext);
            break;
        case NE:
            printf("NE %s\n", yytext);
            break;
        case AND:
            printf("AND %s\n", yytext);
            break;
        case OR:
            printf("OR %s\n", yytext);
            break;
        case INCREMENT:
            printf("INCREMENT %s\n", yytext);
            break;
        case DECREMENT:
            printf("DECREMENT %s\n", yytext);
            break;
        case OPEN_PAREN:
            printf("OPEN_PAREN %s\n", yytext);
            break;
        case CLOSE_PAREN:
            printf("CLOSE_PAREN %s\n", yytext);
            break;
        case OPEN_CURLY:
            printf("OPEN_CURLY %s\n", yytext);
            break;
        case CLOSE_CURLY:
            printf("CLOSE_CURLY %s\n", yytext);
            break;
        case OPEN_BRACK:
            printf("OPEN_BRACK %s\n", yytext);
            break;
        case CLOSE_BRACK:
            printf("CLOSE_BRACK %s\n", yytext);
            break;
        case PLUS:
            printf("PLUS %s\n", yytext);
            break;
        case MINUS:
            printf("MINUS %s\n", yytext);
            break;
        case MULTIPLY:
            printf("MULTIPLY %s\n", yytext);
            break;
        case DIVIDE:
            printf("DIVIDE %s\n", yytext);
            break;
        case NOT:
            printf("NOT %s\n", yytext);
            break;
        case COMMA:
            printf("NOT %s\n", yytext);
            break;
    }
}



char* escape_chars() {
    int i = 0;
    char* curr = yytext + 1;
    char* buff = malloc(sizeof(char) * yyleng);
    while (curr < (yytext + yyleng - 1)) {
        if (*curr == '\\') {
            char* next = curr + 1;
            switch (*next) {
                case 'n':
                    buff[i] = '\n';
                    break;
                case '0':
                    buff[i] = '\0';
                    break;
                default:
                    buff[i] = *next;
                    break;
            }
            
            curr += 2;
        } else {
            buff[i] = *curr;
            curr++;
        }
        i++;
    }

    return buff;
}
