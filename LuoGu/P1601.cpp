#include <iostream>
using namespace std;

string s1,s2;

int a[510],b[510],c[510]={0};

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

int main()
{
    addition();
}