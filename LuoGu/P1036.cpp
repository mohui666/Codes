#include <bits/stdc++.h>
using namespace std;

int n,k,p=0;
const int N = 20;
int a[N],b[N];

bool isPrime(int num)
{
    if (num <= 1) 
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) 
        {
            return false;
        }
    }
    return true;
}

void dfs(int start,int depth)
{
    if(depth>k)
    {
        int sum = 0;
        for(int i = 1;i<=k;i++)
        {
            sum += b[i];
        }
        if(isPrime(sum))
        {
            p++;
        }
        return;
    }
    
    for(int i = start;i<=n;i++)
    {
        b[depth] = a[i];
        dfs(i+1,depth+1);
        b[depth] = 0;
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    dfs(1,1);
    printf("%d",p);
}