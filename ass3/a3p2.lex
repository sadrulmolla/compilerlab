%{
	#include<stdio.h>
	int count1=0;
	int count2=0;
	int count3=0;
	int line =0;	
%}
%%
[A-Z]+				{count1++;}
[A-Z][a-z]*			{count2++;}
.					{count3++;}
%%

int yywrap(){} 
int main()
{
	yyin= fopen("input.txt","r");
	yylex(); 
	int x= line-count2;
	printf("\nNumber of proper names in the given input - %d\n", count2);
	printf("\nNumber of acronyms in the given input - %d\n", count1);
  
	return 0; 
} 