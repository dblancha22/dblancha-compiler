%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "expr.h"
    #include "stmt.h"
    #include "decl.h"
    extern char *yytext;
    extern int yylex();
    extern int yyerror(char *str);
    
    struct decl* root;
%}


%token ARRAY
%token AUTO
%token BOOLEAN
%token CHAR
%token ELSE
%token FALSE
%token FOR
%token FUNCTION
%token IF
%token INTEGER
%token PRINT
%token RETURN
%token STRING
%token TRUE
%token VOID
%token WHILE
%token AND
%token OR
%token SEMICOLON
%token COLON
%token EQUALS
%token GT
%token GE
%token LT
%token LE
%token EE
%token NE
%token INCREMENT
%token DECREMENT
%token OPEN_PAREN
%token CLOSE_PAREN
%token OPEN_CURLY
%token CLOSE_CURLY
%token OPEN_BRACK
%token CLOSE_BRACK

%token IDENTIFIER
%token CHAR_LITERAL
%token INTEGER_LITERAL
%token BOOLEAN_LITERAL
%token STRING_LITERAL
%token COMMENT

%token REMAINDER
%token EXP
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token NOT
%token QUESTION
%token COMMA
%token TOKEN_ERROR
%token TOKEN_EOF

%union {
      struct decl* decl;
      struct stmt* stmt;
      struct expr* expr;
      char* str;
      struct type* type;
      struct param_list* param_list;
}

%type <str> INTEGER_LITERAL CHAR_LITERAL STRING_LITERAL BOOLEAN_LITERAL IDENTIFIER

%type <expr> expr_1 expr_2 expr_3 expr_4 expr_5 expr_6 expr_7 expr_8 expr_9 expr_10 expr expr_list expr_epsilon func_call func_args func_args_e array_start brack_list expr_1_epsilon if_loop

%type <stmt> stmt_0 if_stmt else_stmt closed_if stmt stmts_epsilon bunch_o_stmts

%type <type> type_func type_var type_param type_var_arr

%type <param_list> param_epsilon param_list

%type <decl> decl_func decl_var decl_list

%%


program: decl_list {root = $1; }
       | /*epsilon*/ { root = NULL; }
       ;

decl_list: decl_var decl_list { $$ = decl_create_list($1, $2); }
         | decl_func decl_list { $$ = decl_create_list($1, $2); }
         | decl_var { $$ = $1; }
         | decl_func { $$ = $1; }
         ;

decl_var: IDENTIFIER COLON type_var SEMICOLON { $$ = decl_create($1, $3, NULL, NULL, NULL); }
        /* | IDENTIFIER COLON type_var EQUALS expr_1 SEMICOLON { $$ = decl_create($1, $3, $5, NULL, NULL); } */
        | IDENTIFIER COLON type_var_arr EQUALS expr_1 SEMICOLON { $$ = decl_create($1, $3, $5, NULL, NULL); }
        ;

decl_func: IDENTIFIER COLON FUNCTION type_func EQUALS OPEN_CURLY bunch_o_stmts CLOSE_CURLY { $$ = decl_create_func($1, $4, $7); }
         | IDENTIFIER COLON FUNCTION type_func SEMICOLON { $$ = decl_create($1, $4, NULL, NULL, NULL); }
         ;

type_var: INTEGER { $$ = type_create(TYPE_INTEGER, NULL, NULL); }
        | BOOLEAN { $$ = type_create(TYPE_BOOLEAN, NULL, NULL); }
        | STRING { $$ = type_create(TYPE_STRING, NULL, NULL); }
        | CHAR { $$ = type_create(TYPE_CHARACTER, NULL, NULL); }
        | AUTO { $$ = type_create(TYPE_AUTO, NULL, NULL); }
        | ARRAY OPEN_BRACK expr_1 CLOSE_BRACK type_var { $$ = type_create_arr($3, $5); }
        /* | ARRAY OPEN_BRACK CLOSE_BRACK type_var { $$ = type_create_arr(NULL, $4); } */
        ;

type_var_arr: INTEGER { $$ = type_create(TYPE_INTEGER, NULL, NULL); }
            | BOOLEAN { $$ = type_create(TYPE_BOOLEAN, NULL, NULL); }
            | STRING { $$ = type_create(TYPE_STRING, NULL, NULL); }
            | CHAR { $$ = type_create(TYPE_CHARACTER, NULL, NULL); }
            | AUTO { $$ = type_create(TYPE_AUTO, NULL, NULL); }
            | ARRAY OPEN_BRACK expr_1 CLOSE_BRACK type_var { $$ = type_create_arr($3, $5); }
            | ARRAY OPEN_BRACK CLOSE_BRACK type_var { $$ = type_create_arr(NULL, $4); }
            ;

type_func: INTEGER param_epsilon { $$ = type_create_func(TYPE_INTEGER, $2); }
         | BOOLEAN param_epsilon { $$ = type_create_func(TYPE_BOOLEAN, $2); }
         | STRING param_epsilon { $$ = type_create_func(TYPE_STRING, $2); }
         | CHAR param_epsilon { $$ = type_create_func(TYPE_CHARACTER, $2); }
         | VOID param_epsilon { $$ = type_create_func(TYPE_VOID, $2); }
         | FUNCTION type_func param_epsilon { $$ = type_create(TYPE_FUNCTION, $2, $3); }
         | AUTO param_epsilon { $$ = type_create_func(TYPE_AUTO, $2); }
         ;

param_epsilon: OPEN_PAREN param_list CLOSE_PAREN { $$ = $2; }
             | OPEN_PAREN /* epsilon*/ CLOSE_PAREN { $$ = NULL; }
             ;

param_list: IDENTIFIER COLON type_param COMMA param_list { $$ = param_list_create($1, $3, $5); }
          | IDENTIFIER COLON type_param { $$ = param_list_create($1, $3, NULL); }
          ;

type_param: INTEGER { $$ = type_create(TYPE_INTEGER, NULL, NULL); }
          | BOOLEAN { $$ = type_create(TYPE_BOOLEAN, NULL, NULL); }
          | STRING { $$ = type_create(TYPE_STRING, NULL, NULL); }
          | CHAR { $$ = type_create(TYPE_CHARACTER, NULL, NULL); }
          | AUTO { $$ = type_create(TYPE_AUTO, NULL, NULL); }
          | FUNCTION { $$ = type_create(TYPE_FUNCTION, NULL, NULL); }
          /* | ARRAY OPEN_BRACK expr_1 CLOSE_BRACK type_param */
          | ARRAY OPEN_BRACK CLOSE_BRACK type_param { $$ = type_create(TYPE_ARRAY, $4, NULL); }
          ;

stmt_0: if_stmt { $$ = $1; }
      ;

if_stmt: else_stmt { $$ = $1; }
       | closed_if { $$ = $1; }
       ;

if_loop: OPEN_PAREN expr_1 CLOSE_PAREN { $$ = $2; }

else_stmt: IF if_loop else_stmt ELSE else_stmt { $$ = stmt_create(STMT_IF_ELSE, NULL, NULL, $2, NULL, $3, $5, NULL); }
         | FOR OPEN_PAREN expr_1_epsilon SEMICOLON expr_1_epsilon SEMICOLON expr_1_epsilon CLOSE_PAREN else_stmt { $$ = stmt_create(STMT_FOR, NULL, $3, $5, $7, $9, NULL, NULL); }
         | stmt { $$ = $1; }
         ;

closed_if: IF if_loop if_stmt {$$ = stmt_create(STMT_IF_ELSE, NULL, NULL, $2, NULL, $3, NULL, NULL); }
         | IF if_loop else_stmt ELSE closed_if {$$ = stmt_create(STMT_IF_ELSE, NULL, NULL, $2, NULL, $3, $5, NULL); }
         | FOR OPEN_PAREN expr_1_epsilon SEMICOLON expr_1_epsilon SEMICOLON expr_1_epsilon CLOSE_PAREN closed_if { $$ = stmt_create(STMT_FOR, NULL, $3, $5, $7, $9, NULL, NULL); }
         ;

stmt: RETURN expr_1_epsilon SEMICOLON { $$ = stmt_create(STMT_RETURN, NULL, NULL, $2, NULL, NULL, NULL, NULL); }
    | OPEN_CURLY stmts_epsilon CLOSE_CURLY { $$ = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, $2, NULL, NULL); }
    | PRINT expr_epsilon SEMICOLON { $$ = stmt_create_print($2); }
    | expr_1 SEMICOLON { $$ = stmt_create(STMT_EXPR, NULL, NULL, $1, NULL, NULL, NULL, NULL); }
    | decl_var { $$ = stmt_create(STMT_DECL, $1, NULL, NULL, NULL, NULL, NULL, NULL); }
    ;

stmts_epsilon: bunch_o_stmts { $$ = $1; }
              | /*epsilon*/ { $$ = NULL; }
              ;

bunch_o_stmts: stmt_0 bunch_o_stmts { $$ = stmt_create_list($1, $2); }
             | stmt_0 { $$ = $1; }
             ;

expr_1_epsilon: expr_1 { $$ = $1; }
              | /*epsilon*/ {$$ = NULL; }
              ;

expr_1: expr_2 EQUALS expr_1 { $$ = expr_create(EXPR_EQ, $1, $3); }
      | expr_2 QUESTION expr_1 COLON expr_1 { $$ = expr_create_tern($1, $3, $5); }
      | expr_2 { $$ = $1; }
      ;

expr_2: expr_2 OR expr_3 { $$ = expr_create(EXPR_OR, $1, $3); }
      | expr_3 { $$ = $1; }
      ;

expr_3: expr_3 AND expr_4 { $$ = expr_create(EXPR_AND, $1, $3); }
      | expr_4 { $$ = $1; }
      ;

expr_4: expr_4 GT expr_5 { $$ = expr_create(EXPR_GT, $1, $3); }
      | expr_4 GE expr_5 { $$ = expr_create(EXPR_GE, $1, $3); }
      | expr_4 LT expr_5 { $$ = expr_create(EXPR_LT, $1, $3); }
      | expr_4 LE expr_5 { $$ = expr_create(EXPR_LE, $1, $3); }
      | expr_4 EE expr_5 { $$ = expr_create(EXPR_EE, $1, $3); }
      | expr_4 NE expr_5 { $$ = expr_create(EXPR_NE, $1, $3); }
      | expr_5 { $$ = $1; }
      ;

expr_5: expr_5 PLUS expr_6 { $$ = expr_create(EXPR_ADD, $1, $3); }
      | expr_5 MINUS expr_6 { $$ = expr_create(EXPR_SUB, $1, $3); }
      | expr_6 { $$ = $1; }
      ;

expr_6: expr_6 MULTIPLY expr_7 { $$ = expr_create(EXPR_MUL, $1, $3); }
      | expr_6 DIVIDE expr_7 { $$ = expr_create(EXPR_DIV, $1, $3); }
      | expr_6 REMAINDER expr_7 { $$ = expr_create(EXPR_REM, $1, $3); }
      | expr_7 { $$ = $1; }
      ;

expr_7: expr_7 EXP expr_8 { $$ = expr_create(EXPR_EXP, $1, $3); }
      | expr_8 { $$ = $1; }
      ;

expr_8: MINUS expr_8 { $$ = expr_create(EXPR_NEG, NULL, $2); }
      | NOT expr_8 { $$ = expr_create(EXPR_NOT, NULL, $2); }
      | expr_9 { $$ = $1; }
      ;

expr_9: expr_9 INCREMENT { $$ = expr_create(EXPR_INC, $1, NULL); }
      | expr_9 DECREMENT { $$ = expr_create(EXPR_DEC, $1, NULL); }
      | expr_10 { $$ = $1; }
      ;

expr_10: OPEN_PAREN expr_1 CLOSE_PAREN { $$ = $2; }
       | func_call { $$ = $1; }
       | array_start { $$ = $1; }
       | expr { $$ = $1; }
       ;

array_start: IDENTIFIER brack_list { $$ = expr_create_arr_start($1, $2); }
            ;

brack_list: OPEN_BRACK expr_1 CLOSE_BRACK brack_list { $$ = expr_create_indeces($2, $4); }
          | OPEN_BRACK expr_1 CLOSE_BRACK { $$ = expr_create_indeces($2, NULL); }
          ;

func_call: IDENTIFIER OPEN_PAREN func_args_e CLOSE_PAREN { $$ = expr_create_func($1, $3); }
         ;

func_args: expr_1 COMMA func_args { $$ = expr_create_args($1, $3); }
         | expr_1 { $$ = expr_create_args($1, NULL); }
         ;

func_args_e: func_args { $$ = $1; }
           | /* epsilon */ { $$ = NULL; }
           ;

expr_epsilon: expr_list { $$ = $1; }
            | /* epsilon */ { $$ = NULL; }
            ;

expr_list: expr_1 COMMA expr_list { $$ = expr_create_list($1, $3); }
         | expr_1 { $$ = $1; }
         ;

expr: INTEGER_LITERAL { $$ = expr_create_integer_literal(atoi($1) ); }
    | BOOLEAN_LITERAL { $$ = expr_create_boolean_literal($1); }
    | CHAR_LITERAL { $$ = expr_create_char_literal(parse_char($1) ); }
    | STRING_LITERAL { $$ = expr_create_string_literal(parse_string($1) ); }
    | IDENTIFIER { $$ = expr_create_name($1); }
    | OPEN_CURLY expr_list CLOSE_CURLY { $$ = expr_create_arr_literal($2); }
    ;

%%

int yyerror(char *str) {
    fprintf(stdout, "parse error: %s\n", str);
}