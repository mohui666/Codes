#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int q[N];
int c;

int main()
{
    int n;
    cin >> n >> c;
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }

    sort(q,q+n);

    long long res = 0;

    for(int i = 0,j1=0,j2=0;i<n;i++)
    {
        while(q[j1]-q[i]<c&&j1<n)
        {
            j1++;
        }
        while(q[j2]-q[i]<=c&&j2<n)
        {
            j2++;
        }
        if(q[j1]-q[i]==c&&j1>=1)
        {
            res += j2 - j1;
        }
    }

    printf("%lld",res);
}