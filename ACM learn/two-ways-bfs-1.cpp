#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef pair<int,int> PII;

const int N = 1100;

int n;
int X1,X2,Y1,Y2;
int g[N][N];
int dist[N][N];
int vis[N][N];
PII q[N*N];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int bfs()
{
    memset(vis,-1,sizeof vis);
    memset(dist,-1,sizeof(dist));
    q[0]={X1,Y1};
    q[1]={X2,Y2};
    int hh = 0,tt=1;
    dist[X1][Y1] = 0;
    dist[X2][Y2] = 0;
    vis[X1][Y1]=1;
    vis[X2][Y2]=2;

    while(hh<=tt)
    {
        auto t = q[hh++];
    
        for(int i = 0;i<=3;i++)
        {
            int a = t.x + dx[i];
            int b = t.y + dy[i];

            if(a<1||a>n||b<1||b>n)
            {
                continue;
            }
            if(g[a][b])
            {
                continue;
            }
            if(vis[a][b]+vis[t.x][t.y]==3)
            {
                return dist[t.x][t.y] + dist[a][b] + 1;
            }

            dist[a][b] = dist[t.x][t.y] + 1;

            if(vis[a][b] == -1)
            {
                vis[a][b] = vis[t.x][t.y];
                q[++tt] = {a,b};
            }

        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            scanf("%1d",&g[i][j]);
        }
    }

    scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);

    int res = bfs();
    printf("%d\n",res);
    return 0;
}