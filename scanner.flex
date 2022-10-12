%{
#include "tokens.h"
%}

DIGIT [0-9]
LETTERS [a-zA-Z]
LETSNUMS [A-Za-z0-9]

%%
[\t\n \r]

\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/ 
\/\/.*                                      

[\"]([^\"\\\n]|\\(.|\n))*[\"] { return STRING_LITERAL; }

array        { return ARRAY; }
auto         { return AUTO; }
boolean      { return BOOLEAN; }
char         { return CHAR; }
else         { return ELSE; }
false        { return BOOLEAN_LITERAL; }
for          { return FOR; }
function     { return FUNCTION; }
if           { return IF; }
integer      { return INTEGER; }
print        { return PRINT; }
return       { return RETURN; }
string       { return STRING; }
true         { return BOOLEAN_LITERAL; }
void         { return VOID; }
while        { return WHILE; }
&& { return AND; }
\|\| { return OR; }
; { return SEMICOLON; }
: { return COLON; }
= { return EQUALS; }
> { return GT; }
>= { return GE; }
\< { return LT; }
\<= { return LE; }
== { return EE; }
!= { return NE; }
\+\+ { return INCREMENT; }
-- { return DECREMENT; }
\( { return OPEN_PAREN; }
\) { return CLOSE_PAREN; }
\{ { return OPEN_CURLY; }
\} { return CLOSE_CURLY; }
\[ { return OPEN_BRACK; }
\] { return CLOSE_BRACK; }

({LETTERS}|_)+({LETSNUMS}|_)* { return IDENTIFIER; }

'([^\'\\\n]|\\(.|\n))' { return CHAR_LITERAL; }
{DIGIT}+ { return INTEGER_LITERAL; }

% { return REMAINDER; }
\^ { return EXP; }
\+ { return PLUS; }
- { return MINUS; }
\* { return MULTIPLY; }
\/ { return DIVIDE; }
! { return NOT; }
\? { return QUESTION; }
, { return COMMA; }
. { return TOKEN_ERROR; }
%%
int yywrap() { return 1; }
