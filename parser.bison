%{
    #include <stdio.h>

    extern char *yytext;
    extern int yylex();
    extern int yyerror(char *str);
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

%%

program: decl_list
       | /*epsilon*/
       ;

decl_list: decl_var decl_list
         | decl_func decl_list
         | decl_var
         | decl_func
         ;

decl_var: IDENTIFIER COLON type_var SEMICOLON
        | IDENTIFIER COLON type_var EQUALS expr_1 SEMICOLON
        ;

decl_func: IDENTIFIER COLON FUNCTION type_func OPEN_PAREN param_epsilon CLOSE_PAREN EQUALS OPEN_CURLY bunch_o_stmts CLOSE_CURLY
         | IDENTIFIER COLON FUNCTION type_func OPEN_PAREN param_epsilon CLOSE_PAREN SEMICOLON
         ;

type_var: INTEGER
        | BOOLEAN 
        | STRING
        | CHAR
        | AUTO
        | ARRAY OPEN_BRACK expr_1 CLOSE_BRACK type_var
        ;

type_func: INTEGER
         | BOOLEAN
         | STRING
         | CHAR
         | VOID
         | FUNCTION
         ;

param_epsilon: param_list
             | /* epsilon*/
             ;

param_list: IDENTIFIER COLON type_param COMMA param_list
          | IDENTIFIER COLON type_param
          ;

type_param: INTEGER
          | BOOLEAN 
          | STRING
          | CHAR
          | AUTO
          | FUNCTION
          | ARRAY OPEN_BRACK expr_1 CLOSE_BRACK type_param
          | ARRAY OPEN_BRACK CLOSE_BRACK type_param
          ;

stmt_0: if_stmt
      ;

if_stmt: else_stmt
       | closed_if
       ;

else_stmt: IF OPEN_PAREN expr_1 CLOSE_PAREN else_stmt ELSE else_stmt
         | FOR OPEN_PAREN expr_1_epsilon SEMICOLON expr_1_epsilon SEMICOLON expr_1_epsilon CLOSE_PAREN else_stmt
         | stmt
         ;

closed_if: IF OPEN_PAREN expr_1 CLOSE_PAREN if_stmt
         | IF OPEN_PAREN expr_1 CLOSE_PAREN else_stmt ELSE closed_if
         | FOR OPEN_PAREN expr_1_epsilon SEMICOLON expr_1_epsilon SEMICOLON expr_1_epsilon CLOSE_PAREN closed_if
         ;

stmt: RETURN expr_1_epsilon SEMICOLON
    | OPEN_CURLY bunch_o_stmts CLOSE_CURLY
    | PRINT expr_epsilon SEMICOLON
    | expr_1 SEMICOLON
    | decl_var
    ;

bunch_o_stmts: stmt_0 bunch_o_stmts
             | stmt_0
             ;

expr_1_epsilon: expr_1
              | /*epsilon*/
              ;

expr_1: expr_2 EQUALS expr_1
      | expr_2 QUESTION expr_1 COLON expr_1
      | expr_2
      ;

expr_2: expr_2 OR expr_3
      | expr_3
      ;

expr_3: expr_3 AND expr_4
      | expr_4
      ;

expr_4: expr_4 GT expr_5
      | expr_4 GE expr_5
      | expr_4 LT expr_5
      | expr_4 LE expr_5
      | expr_4 EE expr_5
      | expr_4 NE expr_5
      | expr_5
      ;

expr_5: expr_5 PLUS expr_6
      | expr_5 MINUS expr_6
      | expr_6
      ;

expr_6: expr_6 MULTIPLY expr_7
      | expr_6 DIVIDE expr_7
      | expr_6 REMAINDER expr_7
      | expr_7
      ;

expr_7: expr_7 EXP expr_8
      | expr_8
      ;

expr_8: MINUS expr_8
      | NOT expr_8
      | expr_9
      ;

expr_9: expr_9 INCREMENT
      | expr_9 DECREMENT
      | expr_10
      ;

expr_10: OPEN_PAREN expr_1 CLOSE_PAREN
       | func_call
       | array_start
       | expr
       ;

array_start: IDENTIFIER brack_list 
            ;

brack_list: OPEN_BRACK expr_1 CLOSE_BRACK brack_list
          | OPEN_BRACK expr_1 CLOSE_BRACK
          ;

func_call: IDENTIFIER OPEN_PAREN expr_epsilon CLOSE_PAREN
         ;

expr_epsilon: expr_list
            | /* epsilon */
            ;

expr_list: expr_1 COMMA expr_list
         | expr_1
         ;

expr: INTEGER_LITERAL
    | BOOLEAN_LITERAL
    | CHAR_LITERAL
    | STRING_LITERAL
    | IDENTIFIER
    | OPEN_CURLY expr_list CLOSE_CURLY
    ;

%%

int yyerror(char *str) {
    fprintf(stdout, "parse error: %s\n", str);
}