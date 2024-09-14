#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int sum = 0;
    int i,tmp;
    for(i = 1;sum < N;i++)
    {
        sum += i;
    }

    int index = N - (sum- i + 1);
    if((i-1)%2==0)
    {
        cout << index   << "/" << i - index;
    }
    else
    {
        cout << i - index << "/" << index;
    }
    return 0;
}