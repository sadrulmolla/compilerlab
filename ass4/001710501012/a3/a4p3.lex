%{ 
  #include "y.tab.h" 
%} 
  
/* Rule Section */
%% 
[0-9]+  { yylval=atoi(yytext); return INTEGER;} 
([0-9])+([.])([0-9])+ { yylval=atof(yytext); return FLOAT;}
[\t] ;
\n {return NL;} 
.   {return yytext[0];} 
%% 

int yylex();
  
int yywrap()  {  
   return 1;  
}