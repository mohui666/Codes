#include <iostream>
#include <algorithm>
using namespace std;

struct goods
{
    int price,num;
};

bool cmp(goods a,goods b)
{
    return a.price < b.price;
}

int main()
{
    int m,n;
    cin >> m >> n;
    int num1 = 0;
    goods a[n];
    for(int i = 0;i<n;i++)
    {
        cin >> a[i].price >> a[i].num;
    }
    sort(a,a+n,cmp);
    for(int i = 0;i<n;i++)
    {
        if(m>a[i].price*a[i].num)
        {
            num1 += a[i].num;
            m -= a[i].price*a[i].num;
        }
        else
        {
            num1 += m/a[i].price;
            break;
        }

    }

    cout << num1;
}