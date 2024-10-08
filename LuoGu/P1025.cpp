#include <bits/stdc++.h>
using namespace std;
int n,k;
const int N = 10;
int arr[N];
int res = 0;

void dfs(int x, int start,int sum)
{
    if(sum>n)
    {
        return;
    }
    if(x  > k)
    {
        if(sum == n)
        {
            res++;
        }
        return;
    }

    for(int i = start;sum + i * (k-x+1)<= n; i++)
    {
        dfs(x + 1, i,sum+i);        
    }
}

int main()
{
    scanf("%d %d",&n,&k);
    dfs(1, 1,0);

    printf("%d",res);
}