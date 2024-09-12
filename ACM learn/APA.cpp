#include <iostream>
using namespace std;

string s1,s2;
int a[101],b[101],c[101]={0};

void strToInt(string s,int n[])
{
    for(int i =0;i<=s.size();i++)
    {
        n[s.size()-i] = s[i] - '0';
    }
}

void addition()
{
    cin >> s1 >> s2;
 
    strToInt(s1,a);
    strToInt(s2,b);

    int la = s1.size(),lb = s2.size();
    int lc = max(la,lb)+1;

    for(int i=1;i<=lc;i++)
    {
        c[i] = a[i] + b[i] + c[i];
        c[i+1] = c[i] /10;
        c[i] %= 10;
    }

    while(c[lc]==0&&lc>1)
    {
        lc--;
    }

    for(int i = lc ;i>=1;i--)
    {       
        cout << c[i];
    }
}

bool cmpstr(string s1,string s2)
{
    if(s1.size()!=s2.size())
    {
        return s1.size() >= s2.size();
    }
    else
    {
        return s1 >= s2;
    }
}

void subtraction()
{
    cin >> s1 >> s2;
    if(!cmpstr(s1,s2))
    {
        swap(s1,s2);
        cout << "-";
    }

    strToInt(s1,a);
    strToInt(s2,b);

    int la = s1.size(),lb = s2.size();
    int lc = max(la,lb);

    for(int i = 1;i<=lc;i++)
    {
        if(a[i]<b[i])
        {
            a[i] += 10;
            c[i+1]--;
        }
        c[i] = a[i] - b[i];
    }

    while(c[lc]==0&&lc>1)
    {
        lc--;
    }

    for(int i = lc ;i>=1;i--)
    {       
        cout << c[i];
    }
}

int main()
{

    addition();
    //subtraction();
}
