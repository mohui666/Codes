#include <iostream>
using namespace std;
const int maxN = 1005;

string s1,s2;
int a[maxN],b[maxN],c[maxN]={0};

void strToInt(string s,int n[])
{
    for(int i = 0;i<=s.size();i++)
    {
        n[s.size()-i] = s[i] - '0';
    }
}

void add()
{
    cin >> s1 >> s2;

    strToInt(s1,a);
    strToInt(s2,b);

    int la = s1.size();
    int lb = s2.size();
    int lc = max(la,lb) + 1;

    for(int i = 1;i<=lc;i++)
    {
        c[i] += a[i] + b[i];
        c[i+1] = c[i] / 10;
        c[i] %= 10;
    }

    while(!c[lc]&&lc>1)
    {
        lc--;
    }

    for(int i = lc;i>=1;i--)
    {
        cout << c[i];
    }
}

bool cmpstr(string str1,string str2)
{
    if(str1.size()!=str2.size())
    {
        return str1.size() >= str2.size();
    }
    else
    {
        return str1 >= str2;  
    }
}

void sub()
{
    cin >> s1 >> s2;
    if(!cmpstr(s1,s2))
    {
        swap(s1,s2);
        cout << "-";
    }

    strToInt(s1,a);
    strToInt(s2,b);

    int la = s1.size();
    int lb = s2.size();
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

    while(!c[lc]&&lc>1)
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
    add();
    //sub();
}