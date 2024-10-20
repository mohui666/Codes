#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +10;
int a[N];
int dp[N];

int main()
{
    int n;
    scanf("%d",&n);

    if(n==0)
    {
        printf("0");
        return 0;
    }

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i = 0;i<n;i++)
    {
        dp[i] = 1;
        for(int j = 0;j<i;j++)
        {
            if(a[j] < a[i])
            {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    int res = 0;
    for(int i = 0;i<n;i++)
    {
        res = max(res,dp[i]);
    }
    printf("%d",res);
}