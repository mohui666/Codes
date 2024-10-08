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
queue<PII> q;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int bfs(int x1,int y1)
{
    memset(dist,-1,sizeof(dist));
    q.push({x1,y1});
    dist[x1][y1] = 0;

    while(q.size())
    {
        auto t = q.front();
        q.pop();
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
            if(dist[a][b] != -1)
            {
                continue;
            }

            q.push({a,b});
            dist[a][b] = dist[t.x][t.y] + 1;

            if(a==X2&&b==Y2)
            {
                return dist[X2][Y2];
            }
        }
    }
    return dist[X2][Y2];
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

    int res = bfs(X1,Y1);
    printf("%d\n",res);
    return 0;
}