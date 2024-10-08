#include <bits/stdc++.h>
using namespace std;
int n,k;
const int N = 10;
char _map[N][N];
bool vis[N];
int res = 0;

void dfs(int x,int count)
{
    if(count==k)
    {
        res++;
        return;
    }

    if(x>=n)
    {
        return;
    }

    for(int j = 0;j<n;j++)
    {
        if(_map[x][j]=='#'&&!vis[j])
        {
            vis[j] = true;
            dfs(x+1,count+1);
            vis[j] = false;
        }
    }

    dfs(x+1,count);
}


int main()
{
    while(scanf("%d %d",&n,&k))
    {
        res = 0;

        if(n==-1)
        {
            break;
        }

        for(int i = 0;i<n;i++)
        {
            cin >> _map[i];
        }
        
        dfs(0,0);

        printf("%d\n",res);
    }

}