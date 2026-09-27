%{
#include <stdio.h>
#include <string.h>
%}

%%
"hello"    { printf("hi"); }
.          { ECHO; }
\n         { ECHO; }
%%

int main()
{
    printf("Enter a string: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}