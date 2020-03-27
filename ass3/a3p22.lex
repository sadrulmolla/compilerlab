%{
#include<stdio.h>
#include<stdlib.h>
int row = 1;
int col = 1;
%}
start \/\*
end   \*\/
%%
\/\/(.*)										{}
{start}.*{end} ;
"if"|"else"|"for"|"int"|"float"|"void"|"return" {printf("|  Keyword   |  %2d   | %2d  |  %7s  |\n+------------+-------+-----+-----------+\n",row,col,yytext);col++;}
"+"|"-"|"*"|"/"   								{printf("|  arith-op  |  %2d   | %2d  |  %7s  |\n+------------+-------+-----+-----------+\n",row,col,yytext);col++;}
"<"|">"											{printf("|    relop   |  %2d   | %2d  |  %7s  |\n+------------+-------+-----+-----------+\n",row,col,yytext);col++;}
"="												{printf("| assign-op  |  %2d   | %2d  |  %7s  |\n+------------+-------+-----+-----------+\n",row,col,yytext);col++;}
";"|","|"("|")"|"{"|"}"							{printf("| punc-symb  |  %2d   | %2d  |  %7s  |\n+------------+-------+-----+-----------+\n",row,col,yytext);col++;}
[a-zA-Z][a-z|0-9]* 								{printf("|     ID     |  %2d   | %2d  |  %7s  |\n+------------+-------+-----+-----------+\n",row,col,yytext);col++;}
[0-9]* 											{printf("|    INUM    |  %2d   | %2d  |  %7s  |\n+------------+-------+-----+-----------+\n",row,col,yytext);col++;}
[0-9]*"."[0-9]+									{printf("|     NUM    |  %2d   | %2d  |  %7s  |\n+------------+-------+-----+-----------+\n",row,col,yytext);col++;}
[0-9]+"."[0-9]*									{printf("|     NUM    |  %2d   | %2d  |  %7s  |\n+------------+-------+-----+-----------+\n",row,col,yytext);col++;}
"!"|"@"|"&"|"^"|"%"|"$"|"#"						{printf("|   Spec-ch  |  %2d   | %2d  |  %7s  |\n+------------+-------+-----+-----------+\n",row,col,yytext);col++;}
\n 												{row++;col=1;}
.												{}

%%
int yywrap()
{
return 1;
}
int main()
{
	yyin= fopen("input.c","r");
	printf("+------------+-------+-----+-----------+\n");
	printf("|  type      |  row  | col |    token  |\n");
	printf("+------------+-------+-----+-----------+\n");
	yylex();
	return 0;
}