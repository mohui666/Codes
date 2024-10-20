#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> A,vector<int> B)
{
    if(A.size()!=B.size())
    {
        return A.size()>B.size();
    }
    for(int i = A.size()-1;i>=0;i--)
    {
        if(A[i]!=B[i])
        {
            return A[i]>B[i];
        }
    }

    return true;
}

vector<int> sub(vector<int> A,vector<int> B)
{
    vector<int> C;
    for(int i = 0,t = 0;i<A.size();i++)
    {
        t = A[i] - t;
        if(i<B.size())
        {
            t -= B[i];
        }
        C.push_back((t+10)%10);
        if(t<0)
        {
            t = 1;
        }
        else
        {
            t = 0;
        }
    }

    while(C.size()>1&&C.back()==0)
    {
        C.pop_back();
    }
    return C;
}

int main()
{
    string a,b;
    cin >> a >> b;
    vector<int> A,B;
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

    if(cmp(A,B))
    {
        auto C = sub(A,B);
        for(int i = C.size()-1;i>=0;i--)
        {
            printf("%d",C[i]);
        }
    }
    else
    {
        printf("-");
        auto C = sub(B,A);
        for(int i = C.size()-1;i>=0;i--)
        {
            printf("%d",C[i]);
        }
    }
}