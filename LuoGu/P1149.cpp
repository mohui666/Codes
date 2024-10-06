#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1000;
int num[N] = {6,2,5,5,4,5,6,3,7,6};
int a[4];
int res = 0;

int sumF(int x)
{
    if(num[x])
    {
        return num[x];
    }
    int sum = 0;
    while(x)
    {
        sum += num[x%10];
        x /= 10;
    }
    return sum;
}


void dfs(int depth,int sum)
{
    if(sum>n)
    {
        return;
    }

    if(depth>3)
    {
        if(a[1] + a[2] == a[3]&&sum==n)
        {
            res++;
        }
        return;
    }

    for(int i = 0;i<=N;i++)
    {
        a[depth] = i;
        dfs(depth+1,sum + sumF(i));
        a[depth] = 0;
    }
}

int main()
{
    scanf("%d",&n);
    n -= 4;
    dfs(1,0);
    printf("%d",res);
}