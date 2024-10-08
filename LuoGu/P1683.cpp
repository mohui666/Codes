#include <bits/stdc++.h>
using namespace std;

int W,H;
const int N = 25;
int maxStep = 1;
vector<string> str;
bool vis[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void dfs(int x, int y)
{
    for(int i = 0;i<4;i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if(a<0||a>=W||b<0||b>=H)
        {
            continue;
        }
        if(str[b][a]=='#')
        {
            continue;
        }
        if(vis[b][a])
        {
            continue;
        }
        
        vis[b][a] = true;
        maxStep++;

        dfs(a,b);

    }

}

int main()
{
    scanf("%d%d",&W,&H);
    str.resize(H);
    for(int i = 0;i<H;i++)
    {
        cin >> str[i];
    }

    for(int j = 0;j<H;j++)
    {
        for(int i = 0;i<W;i++)
        {
            if(str[j][i]=='@')
            {
                vis[j][i] = true;
                dfs(i,j);
            }
        }
    }

    printf("%d",maxStep);
}