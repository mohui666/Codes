#include <bits/stdc++.h>
using namespace std;

int n,m;
const int N = 110;
int _map[N][N];
bool vis[N][N];

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void dfs(int x,int y)
{
    vis[x][y]=true;
    
    for(int i = 0;i<4;i++)
    {

        int a = x + dx[i],b = y + dy[i];
        if(a<0||a>=n||b<0||b>=m)
        {
            continue;
        }
        if(vis[a][b]||!_map[a][b])
        {
            continue;
        }
        
        dfs(a,b);
    }
}

int main()
{
    int cells = 0;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            scanf("%1d",&_map[i][j]);
        }
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(!vis[i][j]&&_map[i][j])
            {
                dfs(i,j);
                cells++;
            }
        }
    }


    printf("%d",cells);
}