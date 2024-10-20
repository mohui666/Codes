#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int h[N],ph[N],hp[N],Size;

int n;

void swap_heap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

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
    if(u!=t)
    {
        swap_heap(u,t);
        down(t);
    }
}

void up(int u)
{
    while(u/2&&h[u/2]>h[u])
    {
        swap_heap(u/2,u);
        u >>=1;
    }
}

int main()
{
    cin >> n;
    int id = 0;
    while(n--)
    {
        char op[10];
        int k,x;
        scanf("%s",op);
        if(strcmp(op, "I") == 0)
        {
            scanf("%d", &x);
            Size++;
            id++;
            ph[id] = Size;
            hp[Size] = id;
            h[Size] = x;
            up(Size);
        }
        else if(strcmp(op, "PM") == 0)
        {
            printf("%d\n",h[1]);
        }
        else if(strcmp(op, "DM") == 0)
        {
            swap_heap(1,Size);
            Size--;
            down(1);
        }
        else if(strcmp(op, "D") == 0)
        {
            scanf("%d", &k);
            k = ph[k];
            swap_heap(k,Size);
            Size--;
            down(k);
            up(k);
        }
        else if(strcmp(op, "C") == 0)
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k);
            up(k);
        }
    }
}