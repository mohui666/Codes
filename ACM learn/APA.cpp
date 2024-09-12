#include <iostream>
using namespace std;

string s1,s2;
int a[101],b[101],c[101]={0};
long long d;
int tmp;

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

void divide()
{
    cin >> s1 >> d;

    for(int i =0;i<=s1.size();i++)
    {
        a[i+1] = s1[i] - '0';
    }

    int la = s1.size();

    for(int i = 1;i<=la;i++)
    {
        c[i] = (tmp*10 + a[i]) / d;
        tmp = (tmp*10 + a[i]) % d;
    }
    int lc = 1;
    while(!c[lc]&&lc<la)
    {
        lc++;
    }

    cout << tmp << endl;
    for(int i = lc;i <= la;i++)
    {
        cout << c[i];
    }
}

int main()
{
    //addition();
    //subtraction();
    //multiple();
    divide();
}
