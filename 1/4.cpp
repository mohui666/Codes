#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> A,vector<int>B)
{
    vector<int> C;
    int t = 0;
    int n = max(A.size(),B.size());
    for(int i = 0;i<n;i++)
    {
        if(i<A.size())
        {
            t += A[i];
        }
        if(i<B.size())
        {
            t += B[i];
        }

        C.push_back(t%10);
        t/=10;
    }

    if(t)
    {
        C.push_back(1);
    }

    return C;
}

int main()
{
    string a,b;
    vector<int> A,B;
    cin >> a >> b;
    for(int i = a.size()-1;i>=0;i--)
    {
        int t = a[i] - '0';
        A.push_back(t);
    }

    for(int i = b.size()-1;i>=0;i--)
    {
        int t = b[i] - '0';
        B.push_back(t);
    }

    auto C = add(A,B);

    for(int i = C.size()-1;i>=0;i--)
    {
        printf("%d",C[i]);
    }

}