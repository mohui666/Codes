#include <bits/stdc++.h>
using namespace std;

string end1 = "123804765";
unordered_map<string,int> dist;
unordered_map<string,int> vis;
queue<string> q;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int bfs(string start)
{
    q.push(start);
    q.push(end1);
    dist[end1] = 0;
    dist[start] = 0;
    vis[start] = 1;
    vis[end1] = 2;

    while(q.size())
    {
        auto t = q.front();
        q.pop();

        int distance = dist[t];
        int flag = vis[t];

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

            if(vis[t] + flag == 3)
            {
                int tmp1 = dist[t];
                swap(t[a],t[tmp]);
                int tmp2 = dist[t];
                return tmp1 + tmp2 + 1;
            }

            if(!dist.count(t))
            {
                dist[t] = distance + 1;
                vis[t] = flag;
                q.push(t);
            }

            swap(t[a],t[tmp]);
        }
    }
    return 0;
}

int main()
{
    string start;
    cin >> start;
    
    if(end1==start)
    {
        cout << "0";
        return 0;
    }

    int res = bfs(start);
    cout << res;
}