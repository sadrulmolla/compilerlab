%{
	#include<stdio.h>
	int count1=0;
	int count2=0;
	int count3=0;
%}
%%
\n 				{count1++;count2++;}
[ ]				{count2++;count3++;} 
\t 				{count2++;}
. 				{count3++;}
%%
int yywrap(){} 
int main()
{
	yylex(); 
	printf("\nNumber of linesn in the given input - %d\n", count1);
	printf("\nNumber of words in the given input - %d\n", count2);
	printf("\nNumber of charecter in the given input - %d\n", count3);
  
	return 0; 
} 