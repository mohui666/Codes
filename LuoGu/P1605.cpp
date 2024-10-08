#include <bits/stdc++.h>
using namespace std;

int n,m,t,ways=0;
const int N = 10;
int _map[N][N];
bool vis[N][N];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int startX,startY,finalX,finalY;

void dfs(int x,int y)
{
    if(x==finalX&&y==finalY)
    {
        ways++;
        return;
    }

    for(int i = 0;i<4;i++)
    {
        int a = x+dx[i],b=y+dy[i];
        if(a<=0||a>n||b<=0||b>m)
        {
            continue;
        }
        if(_map[a][b])
        {
            continue;
        }
        if(vis[a][b])
        {
            continue;
        }
        vis[x][y]=1;
        dfs(a,b);
        vis[x][y]=0;
    }
}

int main()
{
    memset(_map,0,sizeof(_map));
    scanf("%d %d %d",&n,&m,&t);
    scanf("%d %d %d %d",&startX,&startY,&finalX,&finalY);
    vis[startX][startY]=1;
    for(int i = 1;i<=t;i++)
    {
        int tmpx,tmpy;
        scanf("%d %d",&tmpx,&tmpy);
        _map[tmpx][tmpy]=1;
    }
    dfs(startX,startY);
    printf("%d",ways);
}