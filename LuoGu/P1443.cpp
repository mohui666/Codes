#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
const int N = 450;
int step[N][N];

typedef pair<int,int> PII;

queue<PII> q;

int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};

void bfs(int x1,int y1)
{
    q.push({x1,y1});
    step[x1][y1] = 0;

    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(int i = 0;i<=7;i++)
        {
            int a = t.first+dx[i];
            int b = t.second+dy[i];

            if(a<1||a>n||b<1||b>m)
            {
                continue;
            }
            if(step[a][b]!=-1)
            {
                continue;
            }

            q.push({a,b});
            step[a][b] = step[t.first][t.second] + 1;
        }
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    memset(step,-1,sizeof step);
    bfs(x,y);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            printf("%d ",step[i][j]);
        }
        printf("\n");
    }
}