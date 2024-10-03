#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num = 0;
    while(n--)
    {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        if(a[0]+a[1]+a[2]>=2)
        {
            num++;
        }
    }
    cout << num;
}