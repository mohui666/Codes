#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n;
int _mapX[N];
int _mapY[N];
int _mapZ1[2*N];
int _mapZ2[2*N];
int res = 0;

void dfs(int x)
{
    if(x>n)
    {
        if(res<=2)
        {
            for(int i = 1; i <= n; i++)
            {
                printf("%d ",_mapX[i]);
            }
            printf("\n");
        }
        res++;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        int z1 = i - x + n;
        int z2 = i + x;
        if((!_mapY[i]) && (!_mapZ1[z1]) && (!_mapZ2[z2]))
        {
            _mapX[x] = i;
            _mapY[i] = 1;
            _mapZ1[z1] = 1;
            _mapZ2[z2] = 1;
            dfs(x + 1);
            _mapY[i] = 0;
            _mapZ1[z1] = 0;
            _mapZ2[z2] = 0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    printf("%d",res);
}