/*Name - Sadrul Alam Molla
roll - 001710501012
class - BCSE-III
assignment 2 

Write a program to convert a program written in simple and restricted C language into a stream of tokens*/

#include <bits/stdc++.h>
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

bool is_keyword(string str)
{
	return ((str=="if")||(str=="else")||(str=="return")||(str=="int")||(str=="float")||(str=="void")||(str=="for")||(str=="while")||(str=="do")||(str=="#include")||(str=="#define"));
}

bool is_id(string str)
{
	if(!((str[0]=='_')||(str[0]>='a'&&str[0]<='z')||(str[0]>='A'&&str[0]<='Z'))) return false;
	for(int i=1;i<str.length();i++)
	{
		if(!((str[i]=='_')||(str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9'))) return false;
	}
	return true;
}

bool is_inum(string str)
{
	for(int i=0;i<str.length();i++)
	{
		if(!(str[i]>='0'&&str[i]<='9')) return false;
	}
	return true;
}

bool is_num(string str)
{
	bool point_encountered=false;
	for(int i=0;i<str.length();i++)
	{
		if(!((str[i]>='0'&&str[i]<='9')||(str[i]=='.'&&!point_encountered))) return false;
		if(str[i]=='.') point_encountered=true;
	}
	return true;
}

int main()
{
	string filename;
	cout<<"Enter file name(.c/.cpp): ";
	cin>>filename;
	
	fstream codef(filename);
	
	int prevcolno=1,colno=1,prevrowno=1,rowno=1,tokenid=1;
	
	bool err=false,delim_encountered=false,word_end=false,backslash=false,cmt1=false,cmt2=false,star=false;
	string str,tokentype;
	char c;
	cout<<"================================================================\n";
	cout<<"Tokenid	|	lexeme	|   rowno   |	colno |	tokentype	\n";
	cout<<"================================================================\n";
	while(codef.get(c))
	{
	  	if(cmt2)
	  	{
	  		if(c=='*') star=true;
	  		else
	  		{
				if(star&&c=='/') cmt2=false;
				star=false;
			}
		}
	  	else
	  	{
	  		if(is_delim(c)||is_arithop(c)||is_relop(c)||is_assignop(c)||is_punch(c)) word_end=true;
	  		else word_end=false;
	  		if(backslash&&(c!='/' && c!='*')&&!(cmt1||cmt2))
	  		{
		  		cout<<tokenid<<"\t\t/\t\t"<<prevrowno<<"\t"<<prevcolno<<"\tARITH-OP\n";
		  		cout<<"------------------------------------------------------------------\n";
		  		backslash=false;
		  	}
		  	if(word_end)
		  	{
				if(!delim_encountered)
		  		{
					cout<<tokenid<<"\t\t"<<str<<"\t\t"<<prevrowno<<"\t"<<prevcolno;
					if(is_keyword(str)) cout<<"\tKEYWORD\n";
					else if(is_inum(str)) cout<<"\tINUM\n";
					else if(is_num(str)) cout<<"\tNUM\n";
					else if(is_id(str)) cout<<"\tID\n";
					else
					{
						cout<<"\tERROR\n";
						err=true;
					}
		  			str="";
		  			delim_encountered=true;
		  			cout<<"------------------------------------------------------------------\n"; 
		  			tokenid++;
				}
				if(!is_delim(c))
				{
					prevrowno=rowno;
					prevcolno=colno;
				
					if(is_arithop(c))
			  		{
			  			if(c=='/')
			  			{
					  		if(!backslash)backslash=true;
					  		else {cmt1=true;backslash=false;}
						}
						else if(c=='*' && (backslash))
						{
							cmt2=true;
							backslash=false;
						}
						else
			  			{
							cout<<tokenid<<"\t\t"<<c<<"\t\t"<<rowno<<"\t"<<colno<<"\tARITH-OP\n";
							cout<<"------------------------------------------------------------------\n";
				  			tokenid++;
			  			}
			  		
			  		} 
				  	if(is_relop(c))
				  	{
				  		cout<<tokenid<<"\t\t"<<c<<"\t\t"<<rowno<<"\t"<<colno<<"\tREL-OP\n";
				  		cout<<"------------------------------------------------------------------\n"; 
				  		tokenid++;
				  	} 
				  	if(is_assignop(c))
				  	{
				  		cout<<tokenid<<"\t\t"<<c<<"\t\t"<<rowno<<"\t"<<colno<<"\tASSIGN-OP\n";
				  		cout<<"------------------------------------------------------------------\n";
				  		tokenid++;
				  	} 
				  	if(is_punch(c))
				  	{
				  		cout<<tokenid<<"\t\t"<<c<<"\t\t"<<rowno<<"\t"<<colno<<"\tPUNCTUATION-OP\n";
				  		cout<<"------------------------------------------------------------------\n";
				  		tokenid++;
				  	}
				}
	   		}
	  		else
	  		{
	  			str+=c;
	  			if(delim_encountered)
	  			{
					prevrowno=rowno;
					prevcolno=colno;
					delim_encountered=false;  
				}
	 		}
		}
	  	if(c=='\n')
	  	{
			rowno++;
			colno=1;
			cmt1=false;
	  	}
	  	else
	  	{
			if(c=='\t') colno+=4;
			else colno++;
	  	}
	}
	if(!err)
	{
		cout<<"Lexical analysis: no error found"<<endl;
	}
	return 0;
}
