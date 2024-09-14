#include <iostream>
using namespace std;

int main()
{
    int n;
    int m[3][2];
    cin >> n;
    cin >> m[0][0] >> m[0][1];
    cin >> m[1][0] >> m[1][1];
    cin >> m[2][0] >> m[2][1];
    int min = 1000000000;
    int a[3]={1};
    while(a[0]*m[0][0]<n)
    {
        a[0]++;
    }
    while(a[1]*m[1][0]<n)
    {
        a[1]++;
    }
    while(a[2]*m[2][0]<n)
    {
        a[2]++;
    }
    for(int i = 0;i<3;i++)
    {
        if(min > a[i]*m[i][1])
        {
            min = a[i]*m[i][1];
        }
    }

    cout << min;
}