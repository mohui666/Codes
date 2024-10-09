#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int step[N][N];

typedef pair<int,int> PII;

queue<PII> q;

int dx[]={1,1,-1,-1,2,2,-2,-2,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1,2,-2,2,-2};

void bfs(int x,int y)
{
    memset(step,-1,sizeof(step));
    q.push({x,y});
    step[x][y] = 0;

    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(int i = 0;i<12;i++)
        {
            int a = t.first+dx[i];
            int b = t.second+dy[i];

            if(a<1||b<1)
            {
                continue;
            }
            if(step[a][b]!=-1)
            {
                continue;
            }

            q.push({a,b});
            step[a][b] = step[t.first][t.second] + 1;
            if(a==1&&b==1)
            {
                return;
            }
        }
    }
}


int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    bfs(x,y);
    q= queue<PII>();
    printf("%d\n",step[1][1]);
    scanf("%d %d",&x,&y);
    bfs(x,y);
    printf("%d\n",step[1][1]);
}