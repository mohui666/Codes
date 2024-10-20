#include <bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int> A,int b)
{
    vector<int> C;
    int t = 0;
    for(int i = 0;i<A.size()||t;i++)
    {
        if(i<A.size())
        {
            t += A[i] * b;
        }

        C.push_back(t%10);
        t/=10;
    }
    return C;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;
    if(b==0)
    {
        cout << 0;
        return 0;
    }

    vector<int> A;
    for(int i = a.size()-1;i>=0;i--)
    {
        int t = a[i] - '0';
        A.push_back(t);
    }

    auto C = mul(A,b);

    for(int i = C.size()-1;i>=0;i--)
    {
        printf("%d",C[i]);
    }
}