#include <iostream>
using namespace std;

int main()
{
    int k,i;
    cin >> k;
    double sum=0.0;
    for(i = 1;;i++)
    {
        sum += 1.0/i;
        if(sum > k*1.0)
        {
            break;
        }
    }
    cout << i;
    return 0;
}