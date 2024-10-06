#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 20;
bool st[N];
int a[N];

void dfs(int x)
{
    if(x>n)
    {
        for(int i =1;i<=n;i++)
        {
            printf("%5d",a[i]);
        }
        cout << endl;
        return;
    }
    
    for(int i = 1;i<=n;i++)
    {
        if(!st[i])
        {
            st[i] = true;
            a[x] = i;
            dfs(x+1);
            st[i] = false;
            a[x] = 0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}