#include <iostream>
using namespace std;

int main()
{
    int n,m,k,a;
    cin >> n >> m >> k;
    int day[1010][1010]={0};
    
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            cin >> a;
            day[a][j] = 1;
        }
    }

    for(int i = 1;i<=k;i++)
    {
        int sum = 0;
        for(int j = 1;j<=m;j++)
        {
            sum += day[i][j];
        }
        cout << sum << " ";
    }
    return 0;
}