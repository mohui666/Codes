#include <bits/stdc++.h>
using namespace std;

string end1 = "123804765";
unordered_map<string,int> dist;
queue<string> q;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int bfs(string start)
{
    q.push(start);
    dist[start] = 0;

    while(q.size())
    {
        auto t = q.front();
        q.pop();

        if(t==end1)
        {
            return dist[t];
        }

        int distance = dist[t];

        int a = t.find('0');
        int x = a/3,y=a%3; 

        for(int i = 0;i<4;i++)
        {
            int X1 = x + dx[i];
            int Y1 = y + dy[i];

            if(X1<0||X1>=3||Y1<0||Y1>=3)
            {
                continue;
            }

            int tmp = X1 * 3 + Y1;
            swap(t[a],t[tmp]);

            if(!dist.count(t))
            {
                dist[t] = distance + 1;
                q.push(t);
            }

            swap(t[a],t[tmp]);
        }
    }
    return -1;
}

int main()
{
    string start;
    cin >> start;

    int res = bfs(start);
    cout << res;
}