#include <bits/stdc++.h>
using namespace std;

int opr[]={'A','B','C'};
string end1;
string start="12345678";
unordered_map<string,int> dist;
unordered_map<string,pair<char,string>> pre;
queue<string> q;

int bfs()
{
    q.push(start);
    dist[start] = 0;

    while(q.size())
    {
        auto t = q.front();
        q.pop();

        if(t==end1)
        {
            return dist[end1];
        }

        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);
    }
}

int main()
{
    for(int i = 1;i<=8;i++)
    {
        scanf("%d",&end[i]);
    }

    int res = bfs();

    cout << res << endl;
}