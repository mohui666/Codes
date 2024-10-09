#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
queue<PII> q;

const int N = 35;
int _map[N][N];
bool st[N][N];
int n;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void bfs(int x,int y)
{
    memset(st,false,sizeof(st));
    q.push({x,y});
    st[x][y] = true;
    while(q.size())
    {
        auto t = q.front();
        q.pop();

        for(int i = 0;i<4;i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if(a<0||a>n + 1||b<0||b>n+1)
            {
                continue;
            }

            if(st[a][b])
            {
                continue;
            }

            if(_map[a][b] == 1)
            {
                continue;
            }

            st[a][b]=1;
            q.push({a,b});
        }
    }
    return;
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            scanf("%d",&_map[i][j]);
        }
    }

    bfs(0,0);

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(_map[i][j]==0&&!st[i][j])
            {
                _map[i][j]=2;
            }

            printf("%d ",_map[i][j]);
        }
        printf("\n");
    }
}