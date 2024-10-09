#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
const int N = 510;

typedef pair<int,int> PII;

queue<PII> q;
int step[N][N];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void bfs()
{
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(int i = 0;i<4;i++)
        {
            int a = t.first+dx[i];
            int b = t.second+dy[i];

            if(a<1||a>n||b<1||b>m)
            {
                continue;
            }
            if(step[a][b]<=step[t.first][t.second]+1&&step[a][b]!=-1)
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
    scanf("%d%d%d%d",&n,&m,&a,&b);


    memset(step,-1,sizeof(step));
    for(int i = 1;i<=a;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        q.push({x,y});
        step[x][y] = 0;
    }

    bfs();

    for(int i = 1;i<=b;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",step[x][y]);
    }

}