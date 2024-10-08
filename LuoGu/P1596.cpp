#include <bits/stdc++.h>
using namespace std;

const int N = 100;
char M[N][N];
int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {1,-1,0,1,-1,0,1,-1};
int m,n,waterCount = 0;

void dfs(int x,int y)
{
    M[x][y]='.';

    for(int i = 0;i<8;i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if(a<0||a>=n||b<0||b>=m)
        {
            continue;
        }
        if(M[a][b]=='.')
        {
            continue;
        }
        
        dfs(a,b);
    }
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i = 0;i<n;i++)
    {
        cin >> M[i];
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(M[i][j]=='W')
            {
                dfs(i,j);
                waterCount++;
            }
        }
    }
    printf("%d",waterCount);
}