/*
This is the standard library of functions for bminor, implemented in C.  
The print statement in bminor expects there to exist a function
for each type that can be printed.  So, the following bminor code:

x: int = 10;
b: boolean = true;
x: string = "hello";

print x, b, s;

Is effectively translated to the following C code:

print_integer(x);
print_boolean(b);
print_string(s);

And the following bminor code:

x = a ^ b;

Is effectively this C code:

x = integer_power(a,b);
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_integer( long x )
{
	printf("%ld",x);
}

void print_string( const char *s )
{
	printf("%s",s);
}

void print_boolean( int b )
{
	printf("%s",b?"true":"false");
}

void print_character( char c )
{
	printf("%c",c);
}

long integer_power( long x, long y )
{
	long result = 1;
	while(y>0) {
		result = result * x;
		y = y -1;
	}
	return result;
}

int string_compare(char* str1, char* str2) {
	return !strcmp(str1, str2);
}