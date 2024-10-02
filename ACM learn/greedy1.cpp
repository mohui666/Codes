#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int total, n;
    cin >> total >> n;

    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        a.push_back(value);
    }

    sort(a.begin(), a.end());

    int num = 0;
    for(int i = n-1;i>=0&&total;i--)
    {
        num += total/a[i];
        total %= a[i];
    }
    cout << num;
}