#include <bits/stdc++.h>
using namespace std;

const int N = 1020;
int v[N] = {0}, w[N] = {0};
int dp[N][N] = {0};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
        }
    }

    printf("%d", dp[m]);
    return 0;
}