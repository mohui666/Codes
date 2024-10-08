#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1e8;
int st[N+50];
int s[N+50],b[N+50];

int sMul = 1;
int bSum = 0;
int _min = 100000;

void dfs(int x)
{
    if(x>n)
    {
        bool flag = 0;
        for(int i = 1;i<=n;i++)
        {
            if(st[i]==1)
            {
                flag = 1;
                sMul *= s[i];
                bSum += b[i];
            }
        }
        if(flag)
        {
            _min = min(_min,abs(sMul-bSum));
        }

        sMul = 1;
        bSum = 0;
        return;
    }

    st[x] = 1;
    dfs(x+1);
    st[x] = 0;

    st[x] = 2;
    dfs(x+1);
    st[x] = 0;
}

int main()
{


    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d %d",&s[i],&b[i]);
    }
    dfs(1);
    printf("%d",_min);
}