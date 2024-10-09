#include <bits/stdc++.h>
using namespace std;

int m;
const int N = 320;
int _time[N][N];
int dist[N][N]; 
int dx[]={0,1,0,-1,0};
int dy[]={1,0,-1,0,0};

typedef pair<int,int> PII;
queue<PII> q;

int bfs()
{
    q.push({0,0});
    dist[0][0] = 0;

    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(int i = 0;i<=3;i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if(a<0||b<0)
            {
                continue;
            }
            
            if(dist[a][b])
            {
                continue;
            }

            if(dist[t.first][t.second] +1 >=_time[a][b])
            {
                continue;
            }

            dist[a][b] = dist[t.first][t.second] + 1;
            q.push({a,b});

            if(_time[a][b]>1e9)
            {
                return dist[a][b];
            }

        }
    }
    return -1;
}

int main()
{
    memset(_time,0x3f,sizeof(_time));
    scanf("%d",&m);
    while(m--)
    {
        int X0,Y0,T0;
        scanf("%d %d %d",&X0,&Y0,&T0);
        for(int i = 0;i<=4;i++)
        {
            int a = X0 + dx[i];
            int b = Y0 + dy[i];
            if(a<0||a>301||b<0||b>301)
            {
                continue;
            }

            _time[a][b] = min(T0,_time[a][b]);
        }
    }

    printf("%d",bfs());

}