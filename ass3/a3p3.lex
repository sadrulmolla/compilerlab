%{
	#include<stdio.h>
	int count1=0;
	int count2=0;
	int count3=0;
	int dec=0;
	int inti=0;
%}
%%
"."[0-9]+		{}
[0-9]+"."		{}
\n 				{count1++;count2++;}
[ ]				{count2++;count3++;} 
\t 				{count2++;}
[a-zA-Z]		{count3++;}
[0-9]+ 			{inti++;}
[0-9]+"."[0-9]+ {dec++;}
%%
int yywrap(){} 
int main()
{
	yyin= fopen("myfile.txt","r");
	yylex(); 
	printf("\nNumber of linesn in the given input - %d\n", count1);
	printf("\nNumber of words in the given input - %d\n", count2);
	printf("\nNumber of charecter in the given input - %d\n", count3);
	printf("\nNumber of intigers in the given input - %d\n", inti);
	printf("\nNumber of decimal in the given input - %d\n", dec);
  
	return 0; 
} 