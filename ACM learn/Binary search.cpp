#include <iostream>
#include <vector>
using namespace std;

//时间复杂度：O(logn)
int binary_search(vector<int>& a,int l,int r,int tar)
{
    if(l>r)
    {
        return -1;
    }
    int mid = (l + r)/2;
    if(a[mid]==tar)
    {
        return mid;
    }
    else if(a[mid]<tar)
    {
        return binary_search(a,mid + 1,r,tar);
    }
    else
    {
        return binary_search(a,l,mid-1,tar);
    }
    return -1;
}

int main()
{
    vector<int> a ={1,2,3,4,5,6,7,8,9,10};
    int tar;
    while(cin>>tar)
    {
        cout << binary_search(a,0,a.size()-1,tar) << endl;
    }
}