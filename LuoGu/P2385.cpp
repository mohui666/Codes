#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

const int N = 35;
int m,n,m1,m2;

int step[N][N];
int _map[N][N];
queue<PII> q;

int dx[8],dy[8];
int X0,Y0,X1,Y1;

int bfs(int x,int y)
{
    memset(step,-1,sizeof(step));
    q.push({x,y});
    step[x][y] = 0;

    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(int i = 0;i<8;i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if(a<1||a>m||b<1||b>n||step[a][b]!=-1||_map[a][b]==0||_map[a][b]==2)
            {
                continue;
            }

            q.push({a,b});
            step[a][b] = step[t.first][t.second] + 1;

            if(a==X1&&b==Y1)
            {
                return step[X1][Y1];
            }
        }
    }
    return step[X1][Y1];
}

int main()
{
    scanf("%d %d %d %d",&m,&n,&m1,&m2);
    dx[0] = m1;dx[1]=m1;dx[2]=-m1;dx[3]=-m1;
    dx[4]= m2;dx[5]=m2;dx[6]=-m2;dx[7]=-m2;
    dy[0] = -m2;dy[1]=m2;dy[2]=-m2;dy[3]=m2;
    dy[4] = -m1;dy[5]=m1;dy[6]=-m1;dy[7]=m1;

    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            scanf("%d",&_map[i][j]);
            if(_map[i][j]==3)
            {
                X0 = i;
                Y0 = j;
            }
            if(_map[i][j]==4)
            {
                X1 = i;
                Y1 = j;
            }
        }
    }
    int res = bfs(X0,Y0);
    printf("%d",res);
}