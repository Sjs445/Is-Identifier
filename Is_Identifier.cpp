#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

bool checkLetter(char[]);
bool checkDigit(char[]);
bool checkUnderscore(char[]);

int main()
{
    char decision[2];
    string strinput;
    char input[100];
    int final=0;
    
    do
    {
        cout<<"Enter a string: ";

        getline(cin, strinput);
        strcpy(input, strinput.c_str());

        if(checkLetter(input))
        {
            final++;
        }
        if(checkDigit(input))
        {
            final++;
        }
        if(checkUnderscore(input))
        {
            final++;
        }

        if(final==3)
        {
            cout<<input<<" is an identifier \n";
        }
        else
        {
            cout<<input<<" is not an identifier \n";
        }
        
        cout<<"CONTINUE(y/n)? ";
        cin>>decision;
        cin.ignore();
        cin.clear();
        final=0;
        
    } while (strcmp(decision, "y")==0);
    
    return 0;
}

bool checkLetter(char input[])
{
    int i=0;
    while(input[i])
    {
        if(isalpha(input[i]))
        {
            return true;
        }
        i++;
    }
    return false;
}

bool checkDigit(char input[])
{
    int i=0;
    if(isdigit(input[i]))
    {
        return false;
    }

    while(input[i++])
    {
        if(isdigit(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool checkUnderscore(char input[])
{
    int i=0;
    while(input[i])
    {
        if(input[i]=='_')
        {
            return true;
        }
        i++;
    }
    return false;
}