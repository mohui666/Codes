#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int s[N];
int m,n;

int main()
{
    cin >> m >> n;
    for(int i = 1;i<=m;i++)
    {
        scanf("%d",&s[i]);
    }

    sort(s+1,s+1+m);

    unsigned long long sum = 0;
    for(int i = 1;i<=n;i++)
    {
        long long x;
        scanf("%d",&x);

        long long l = 1, r = m;

        while(l < r)
        {
            long long mid = (l + r) / 2;
            if(s[mid] >= x)
            {
                r = mid;
            }
            else 
            {
                l = mid + 1;
            }
        }

        if(x <= s[1])
        {
            sum += s[1] - x;
        }
        else if(x >= s[m])
        {
            sum += x - s[m];
        }
        else
        {
            sum += min(abs(s[l-1] - x), abs(s[l] - x));
        }
    }

    printf("%llu",sum);
}