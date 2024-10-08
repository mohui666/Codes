#include <bits/stdc++.h>
using namespace std;

int n,a,b;
const int N = 10000;
int num[N];
int minPress = 1e8;
bool flag;
bool st[N];
int memo[N];

void dfs(int x,int s)
{
    if(s>=minPress)
    {
        return;
    }
    if(x==b)
    {
        flag = 1;
        minPress = min(minPress,s);
        return;
    }

    st[x] = 1;

    int down = x-num[x];
    if(down>0&&!st[down]&&(memo[down] == -1 || s + 1 < memo[down]))
    {
        memo[down] = s + 1;
        dfs(x-num[x],s+1);
    }

    int up = x+num[x];
    if(up<=n&&!st[up]&&(memo[up] == -1 || s + 1 < memo[up]))
    {
        memo[up] = s + 1; 
        dfs(x+num[x],s+1);
    }

    st[x] = false;

}

int main()
{

    scanf("%d %d %d",&n,&a,&b);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    memset(memo, -1, sizeof(memo));
    dfs(a,0);
    if(flag)
    {
        printf("%d",minPress);
    }
    else
    {
        printf("-1");
    }
}