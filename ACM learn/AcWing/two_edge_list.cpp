#include <iostream>
using namespace std;

const int N = 100010;

int e[N],l[N],r[N];
int head,idx;

void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void add(int k,int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main()
{
    int m;
    cin >> m;
    init();
    while(m--)
    {
        char op;
        cin >> op;
        int k,x;
        switch(op)
        {
            case 'L':
                cin >> x; 
                add(0,x);
                break;
            case 'R':
                cin >> x;
                add(l[1],x);
                break;
            case 'D':
                cin >> k;
                remove(k+1);
                break;
            case 'I':
                cin >> op;
                cin >> k >> x;
                if(op=='L')
                {
                    add(l[k+1],x);
                    break;
                }
                else
                {
                    add(k+1,x);
                }
                break;
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) 
    {
        cout << e[i] << " ";
    }

    return 0;
}