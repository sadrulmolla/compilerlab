#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    ifstream fin;
    fin.open ("noun.txt");
    string str;
    printf("Enter the sentence: ");
    getline(cin, str);
    string word,aword;
    stringstream iss(str);
    int isFound;
    set<string>noun;
    set<string>adverb;
    set<string>adjective;
    set<string>verb;
    while (!fin.eof())
    {
        fin>>aword;
        noun.insert(aword);
    }
    fin.close();
    fin.open("adverb.txt");
    while(!fin.eof())
    {
        fin>>aword;
        adverb.insert(aword);
    }
    fin.close();
    fin.open("adjective.txt");
    while(!fin.eof())
    {
        fin>>aword;
        adjective.insert(aword);
    }
    fin.close();
    fin.open("verb.txt");
    while(!fin.eof())
    {
        fin>>aword;
        verb.insert(aword);
    }
    fin.close();
    cout<<"===============================================================================\n";
    while (iss >> word)
    {
        isFound=0;
        cout<<word;
        if(noun.find(word)!=noun.end())
        {
            cout<<" noun ";
            isFound=1;
        }
        if(adverb.find(word)!=adverb.end())
        {
            cout<<" adverb ";
            isFound=1;
        }
        if(adjective.find(word)!=adjective.end())
        {
            cout<<" adjective ";
            isFound=1;
        }
        if(verb.find(word)!=verb.end())
        {
            cout<<" verb ";
            isFound=1;
        }
        if(!isFound)
            cout<<" Not found ";
        cout<<endl;

    }
    cout<<"================================================================================\n";
    return 0;
}

