#include <iostream>
using namespace std;

int main()
{
    long long a[10];
    for(int i = 0;i<10;i++)
    {
        cin >> a[i];
        a[i] -= 30;
    }


    int h,n=0;
    cin >> h;

    for(int i = 0;i<10;i++)
    {
        if(h>=a[i])
        {
            n++;
        }
    }

    cout << n;
}