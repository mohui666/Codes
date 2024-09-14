#include <iostream>
using namespace std;

int main()
{
    string N;
    cin >> N;
    int lc = N.size()-1;
    if(N[0]=='-')
    {
        while(N[lc]=='0'&&lc>1)
        {
            lc--;
        }
        cout << "-";
        for(int i = lc;i>=1;i--)
        {
            cout << N[i];
        }
    }
    else
    {
        while(N[lc]=='0'&&lc>0)
        {
            lc--;
        }
        for(int i = lc;i>=0;i--)
        {
            cout << N[i];
        } 
    }

    return 0;
}