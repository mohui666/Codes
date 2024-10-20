#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int v[N],w[N],s[N];
int dp[N];

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i = 1;i<=m;i++)
    {
        scanf("%d%d%d",&v[i],&w[i],&s[i]);
    }

    for(int i = 1;i<=m;i++)
    {
        for(int k = 1;k<=s[i];k++)
        {
            for(int j = n;j>=v[i];j--)
            {
                dp[j] = max(dp[j],dp[j-v[i]]+w[i]);      
            }
        }
    }
    printf("%d",dp[n]);
}