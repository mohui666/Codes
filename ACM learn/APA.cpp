#include <iostream>
using namespace std;

string s1,s2;
int a[101],b[101],c[101]={0};

void strToInt(string s,int a[])
{
    for(int i =i;i<s1.size();i++)
    {
        a[s.size()-i] = s[i] - '0';
    }
}
int main()
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

    //移除前导0
    while(c[lc]==0&&lc>1)
    {
        lc--;
    }

    for(int i = lc ;i>=1;i--)
    {       
        cout << c[i];
    }
}