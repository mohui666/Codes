#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int a[N][N];
int dp[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(int i = n;i>=1;i--)
    {
        for(int j = 1;j<=n;j++)
        {
            dp[j] = max(dp[j], dp[j+1]) + a[i][j];
        }
    }

    printf("%d",dp[1]);
}