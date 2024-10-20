#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int x[N] = {0}, m[N] = {0};

int main()
{
    int n,q;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&x[i]);
    }

    scanf("%d",&q);
    for(int i = 1;i<=q;i++)
    {
        scanf("%d",&m[i]);
    }

    sort(x+1,x+1+n);

    for (int i = 1; i <= q; i++)
    {
        int coins = m[i];
        int shops = upper_bound(x + 1, x + 1 + n, coins) - (x + 1);
        printf("%d\n", shops);
    }
}