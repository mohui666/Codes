#include <iostream>
using namespace std;

int main()
{
    int l,m;
    cin >> l >> m;
    int tree[l+1];
    for(int i = 0;i<l+1;i++)
    {
        tree[i] = 1;
    }
    while(m--)
    {
        int u ,v;
        cin >> u >> v;
        for(int i = u;i<=v;i++)
        {
            tree[i] = 0;
        }
    }

    int sum = 0;
    for(int i = 0;i<l+1;i++)
    {
        sum += tree[i];
    }

    cout << sum;
}