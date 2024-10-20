#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

int m,n;
const int N = 510;
int high[N][N];
int flag[N][N];
int flags;
bool st[N][N];
queue<PII> q;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int X1,Y1;

bool check(int mid)
{
    memset(st, false, sizeof(st));
    st[X1][Y1] = true;
    q.push({X1, Y1});
    int cnt = 1;
    while(q.size())
    {
        auto t = q .front();
        q.pop();

        for(int i = 0;i < 4;i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if(a<1||b<1||a>m||b>n)
            {
                continue;
            }
            if(abs(high[t.first][t.second] - high[a][b])>mid)
            {
                continue;
            }

            if(st[a][b])
            {
                continue;
            }
            
            st[a][b] = true;
            q.push({a,b});
            if(flag[a][b]==1)
            {
                cnt++;
                if(cnt==flags)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d",&m,&n);
    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            scanf("%d",&high[i][j]);
        }
    }
    
    flags = 0;
    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            scanf("%d",&flag[i][j]); 
            if(flag[i][j]==1)
            {
                flags++;
            }
        }
    }

    bool found = false;
    for(int i = 1;i<=m && !found;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(flag[i][j] == 1)
            {
                X1 = i;
                Y1 = j;
                found = true;
                break;
            }
        }
    }

    int l = -1,r=1e9+10;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        q = queue<PII>();
        if(check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    printf("%d",r);

}