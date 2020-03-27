%{
	#include "y.tab.h"
%}

%%
[aA] {return A;}
[bB] {return B;}
\n   {return NL;}
.    {return yytext[0];}
%%

int yylex();
int yywrap()
{
	return 1;
} 