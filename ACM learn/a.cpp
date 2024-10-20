#include <bits/stdc++.h>
using namespace std;

int a[128];
int main()
{
    a['a']=1,a['e']=1;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for(int i = 0;i<n;i++)
        {
            if(i==n-3)
            {
                cout << s[i] << s[i+1] << s[i+2] << endl;
                break;
            }
            if(i==n-2)
            {
                cout << s[i] << s[i+1] << endl;
                break;
            }
            else
            {
                if(a[s[i+2]]!=a[s[i+3]])
                {
                    cout << s[i] << s[i+1] << ".";
                    i++;
                }
                else
                {
                    cout << s[i] << s[i+1] << s[i+2] << ".";
                    i+=2;
                }
            }
        }
    }
}