#include <iostream>
using namespace std;

int main()
{
    char s;
    int sum = 0;
    while(cin>>s)
    {
        if(s!=' '||s!='\n')
        {
            sum++;
        }
    }

    cout << sum;
    return 0;
}