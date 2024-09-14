#include <iostream>
using namespace std;

void facSum(int a,int m[],int n[])
{
    m[1] = n[1] = 1;
    for(int i = 2;i<=a;i++)
    {
        for(int j = 1;j<=300;j++)
        {
            m[j]*=i;
        }
        for(int j = 1;j<=300;j++)
        {
            if(m[j]>=10)
            {
                m[j+1] += m[j]/10;
                m[j] %= 10;
            }
        }
        for(int j =1;j<=300;j++)
        {
            n[j] += m[j];
            if(n[j]>=10)
            {
                n[j+1]+=n[j]/10;
                n[j]%=10;
            }
        }
    }

    int nBegin = 300;
    while(!n[nBegin]&&nBegin>1)
    {
        nBegin--;
    }
    
    for(int i = nBegin;i>=1;i--)
    {
        cout << n[i];
    }
}
int main()
{
    int n[1000] = {0};
    int m[1000] = {0};
    int num;
    cin >> num;
    facSum(num,m,n);
}
