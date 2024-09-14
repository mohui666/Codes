#include <iostream>
using namespace std;

int main()
{
    int m[13];
    int money=0;
    int saved=0;
    int flag=0;
    for(int i=1;i<=12;i++)
    {
        cin >> m[i];
        money += (300 - m[i]);
        if(money < 0)
        {
            flag = i;
            break;
        }
        saved += money / 100;
        money %= 100;

    }

    if(flag!=0)
    {
        cout << -1*flag;
    }
    else
    {
        cout << 120 * saved + money;
        return 0;
    }
    
}