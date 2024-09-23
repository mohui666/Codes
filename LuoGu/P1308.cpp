#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string a;
    string b;
    getline(cin,a,'\n');
    getline(cin,b,'\n');

    int num = 0;
    if(isupper(a[0]))
    {
        a[0] = tolower(a[0]);
    }

    for(int i = 0;i<b.length();i++)
    {
        if(isupper(b[i]))
        {
            b[i] = tolower(b[i]);
        }
    }

    int firstPos = -1;
    int index = 0;
    string currentWord;
    for (int i = 1; i < b.size(); i++) 
    {
        if (b[i] == ' ') 
        {
            if (currentWord == a) 
            {
                num++;
                if (firstPos == -1) 
                {
                    firstPos = index;
                }
            }
            currentWord.clear();
            index = i + 1;
        } 
        else 
        {
            currentWord += b[i];
        }
    }

    if (currentWord == a) 
    {
        num++;
        if (firstPos == -1) 
        {
            firstPos = index;
        }
    }

    if(!num)
    {
        cout << -1;
    }
    else
    {
        cout << num << " " << firstPos ;
    }
}