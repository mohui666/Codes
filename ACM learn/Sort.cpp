#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& vec)
{
    //时间复杂度：O(n^2)
    //空间复杂度：O(1)
    //稳定性：稳定
    
    for(int j = vec.size() - 1;j>=1;j--)
    {
        bool flag = true;
        for(int i = 0;i<vec.size()-1;i++)
        {
            if(vec[i]>vec[i+1])
            {
                swap(vec[i],vec[i+1]);
                flag = flase;
            }
        }
        if(flag)
        {
            break;
        }
    }
    
}

void print(vector<int>& vec)
{
    for(auto& i : vec)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> vec {1,4,5,6,8,7,3,9,2};
    bubbleSort(vec);
    print(vec);
}