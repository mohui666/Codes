#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N];
bool dp[N];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof dp);
        memset(a,0,sizeof a);
        scanf("%d",&n);
        int sum = 0;
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }

        if(sum%2)
        {
            printf("NO\n");
            continue;
        }

        int target = sum/2;
        
        dp[0] = 1;
        

        for(int i = 1;i<=n;i++)
        {
            for(int j = target;j>=a[i];j--)
            {
                dp[j] = dp[j] || dp[j-a[i]];
            }
        }
        if(dp[target])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}