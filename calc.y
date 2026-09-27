%{
#include <stdio.h>
%}

%token NUM

%left '+' '-'
%left '*' '/'

%%
S : E '\n' { printf("Result = %d\n", $1); }
  ;

E : E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { $$ = $1 / $3; }
  | NUM     { $$ = $1; }
  ;
%%

int main()
{
    printf("Enter expression:\n");
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("Error\n");
    return 0;
}