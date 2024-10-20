#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct carpet
{
    int x,y,a,b,id;
};

stack<carpet> q;

bool check(int x,int y,carpet t)
{
    if((t.x <= x && x <= (t.x + t.a)) && (t.y <= y && y <= (t.y + t.b)))
    {
        return 1;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        int x,y,a,b;
        scanf("%d%d%d%d",&x,&y,&a,&b);
        q.push({x,y,a,b,i});
    }

    int x,y;
    cin >> x >> y;
    while(q.size())
    {
        auto t = q.top();
        q.pop();
        if(check(x,y,t))
        {
            cout << t.id;
            return 0;
        }
    }

    cout << -1;
}