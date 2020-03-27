#include<bits/stdc++.h>

using namespace std;

bool is_delim(char c)
{
	return ((c==' ')||(c=='\t')||(c=='\n'));
}
bool is_punch(char c)
{
	return ((c==',')||(c==';')||(c=='?')||(c=='(')||(c==')')||(c=='[')||(c==']')||(c=='{')||(c=='}'));
}
bool is_arithop(char c)
{
	return ((c=='+')||(c=='-')||(c=='*')||(c=='/'));
}
bool is_relop(char c)
{
	return ((c=='<')||(c=='>'));
}
bool is_assignop(char c)
{
	return (c=='=');
}
int main(void)
{
	string input;
	string filename;
	cout<<"Enter The FileName: ";
	cin>>filename;
	char c;
	bool word_end=false;
	fstream codef(filename);
	regex integer("(\\+|-)?[[:digit:]]+");
	regex floatnum("[+-]?([0-9]*[.])?[0-9]+");
	regex identifier("^[a-zA-Z_][a-zA-Z0-9_]*$");
	while(codef.get(c))
	{
		if(is_delim(c)||is_arithop(c)||is_relop(c)||is_assignop(c)||is_punch(c)) word_end=true;
		else word_end=false;
		if(word_end)
		{
			if(regex_match(input,integer))cout<<"integer-->"<<input<<endl;

			else if(regex_match(input,floatnum))cout<<"Decimal-->"<<input<<endl;

			else if(regex_match(input,identifier))cout<<"identifier-->"<<input<<endl;
			input="";
		}
		else input+=c;
	}
	return 0;
}