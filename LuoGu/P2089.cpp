#include <bits/stdc++.h>
using namespace std;

int n, p = 0;
const int N = 20;
int a[N] = {0};
vector<vector<int>> results;

void dfs(int start,int depth)
{
    if(depth>10)
    {
        int sum = 0;
        for(int i=1;i<=10;i++)
        {
            sum += a[i];
        }
        if(sum==n)
        {
            p++;
            vector<int> result;
            for (int i = 1; i <= 10; i++) 
            {
                result.push_back(a[i]);
            }
            results.push_back(result);
        }
        return;
    }

    for(int i = start;i<=3;i++)
    {
        a[depth] = i;
        dfs(1,depth+1);
        a[depth] = 0;
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1,1);
    printf("%d\n",p);
    for (const auto& result : results) 
    {
        for (int i = 0; i < result.size(); i++) 
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}