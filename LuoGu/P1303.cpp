#include <iostream>
using namespace std;

string s1,s2;
int a[2100],b[2100],c[9999]={0};

void strToInt(string s,int n[])
{
    for(int i =0;i<=s.size();i++)
    {
        n[s.size()-i] = s[i] - '0';
    }
}

void multiple()
{
    cin >> s1 >> s2;

    strToInt(s1,a);
    strToInt(s2,b);

    int la = s1.size(),lb = s2.size();
    int lc = la + lb;

    for(int i = 1;i<=la;i++)
    {
        for(int j = 1;j<=lb;j++)
        {
            c[i+j-1] += a[i] * b[j];
            c[i+j] += c[i+j-1] / 10;
            c[i+j-1] %= 10;
        }
    }

    while(c[lc]==0&&lc>1)
    {
        lc--;
    }

    for(int i = lc;i>=1;i--)
    {
        cout << c[i];
    }
}

int main()
{
    multiple();
}