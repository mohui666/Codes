#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int h[N],Size;

void down(int u)
{
    int t = u;
    if(u*2<=Size&&h[u*2]<h[t])
    {
        t = u*2;
    }
    if(u*2+1<=Size&&h[u*2+1]<h[t])
    {
        t = u*2+1;
    }
    if(t!=u)
    {
        swap(h[u],h[t]);
        down(t);
    }
}

void up(int u)
{
    while(u>>1&&h[u>>1]>h[u])
    {
        swap(h[u>>1],h[u]);
        u>>=1;
    }
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int op;
        int x;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&x);
            h[++Size] = x;
            up(Size);
        }
        else if(op==2)
        {
            printf("%d\n",h[1]);
        }
        else
        {
            swap(h[1],h[Size]);
            Size--;
            down(1);
        }
    }
}