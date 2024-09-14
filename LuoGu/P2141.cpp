#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = a[i] + a[j];
            if(s.find(sum) != s.end())
            {
                count++;
                s.erase(sum);
            }
        }
    }

    cout << count << endl;
    return 0;
}