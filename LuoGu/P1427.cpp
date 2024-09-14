#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a;
    int num;
    for(int i = 0;;i++)
    {
        cin >> num;
        if(num==0)
        {
            break;
        }
        a.push_back(num);
    }

    for(int i = a.size()-1; i >= 0; i--)
    {
        cout << a[i];
        if(i > 0)
        {
            cout << " ";
        }
    }

    return 0;
}