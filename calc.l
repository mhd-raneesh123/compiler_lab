%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+    { yylval = atoi(yytext); return NUM; }
[+\-*/\n] { return yytext[0]; }
[ \t]     ;
.         ;
%%

int yywrap()
{
    return 1;
}