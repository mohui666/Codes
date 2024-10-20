#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
deque<PII> q;
int n,m;
const int N = 510;
string _map[N];
int dist[N][N];
int X1,Y1,X2,Y2;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int bfs()
{
    q.push_back({X1,Y1});
    dist[X1][Y1]=0;

    while(q.size())
    {
        auto t = q.front();
            q.pop_front();

        char ch = _map[t.first][t.second];

        for(int i = 0;i<4;i++)
        {
            int a = t.first+dx[i];
            int b = t.second+dy[i];
                
            if(a<1||b<0||a>n||b>m)
            {
                continue;
            }
            if(dist[a][b]>=0)
            {
                    continue;
                }
                if(_map[a][b]==ch)
                {
                    dist[a][b]=dist[t.first][t.second];
                    q.push_front({a,b});
                }
                if(_map[a][b]!=ch)
                {
                    dist[a][b]=dist[t.first][t.second] + 1;
                    q.push_back({a,b});
                }
    
                if(a==X2&&b==Y2)
                {
                    return dist[X2][Y2];
                }
            }
        }
        return -1;
}


int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        memset(dist,-1,sizeof dist);    
        if(n==0)
        {
            break;
        }
        for(int i = 1;i<=n;i++)
        {
            scanf("%s",_map[i]);
        }
        q.clear();
        scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
        int res = bfs();
        printf("%d\n",res);
    }

}