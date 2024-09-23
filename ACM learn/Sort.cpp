#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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
                flag = false;
            }
        }
        if(flag)
        {
            break;
        }
    }
    
}

void SelectSort(vector<int>& vec)
{
    //时间复杂度：O(n^2)
    //空间复杂度：O(1)
    //稳定性：不稳定

    for(int i = 0;i < vec.size();i++)
    {
        int minIndex = i;
        for(int j = i + 1;j < vec.size();j++)
        {
            if(vec[minIndex]>vec[j])
            {
                minIndex = j;
            }
        }
        swap(vec[i],vec[minIndex]);
    }
}

void InsertSort(vector<int>& vec)
{
    //时间复杂度：O(n^2)
    //空间复杂度：O(1)
    //稳定性：稳定

    for(int j = 1;j<vec.size();j++)
    {
        for(int i = 0;i<j;i++)
        {
            if(vec[j]<vec[i])
            {
                int tmp =vec[j];
                for(int k = j-1;k>=i;k--)
                {
                    vec[k+1] = vec[k];
                }
                vec[i] = tmp;
                break;
            }

        }
    }
}

void ShellInsertSort(vector<int>& vec,int start ,int gap)
{
    for(int j = start+gap;j<vec.size();j+=gap)
    {
        for(int i = start;i<j;i+=gap)
        {
            if(vec[j]<vec[i])
            {
                int tmp =vec[j];
                for(int k = j-gap;k>=i;k-=gap)
                {
                    vec[k+gap] = vec[k];
                }
                vec[i] = tmp;
                break;
            }
        }
    }
}

void ShellSort(vector<int>& vec)
{
    //时间复杂度：O(n^2)
    //空间复杂度：O(1)
    //稳定性：不稳定
    for(int gap = vec.size()/2;gap>=1;gap/=2)
    {
        for(int i = 0;i<gap;i++)
        {
            ShellInsertSort(vec,i,gap);
        }

    }
}

void CountSort(vector<int>& vec)
{
    int maxx = *max_element(vec.begin(), vec.end());
    int* countArr = new int[maxx+1];
    memset(countArr,0,sizeof(int)*(maxx+1));
    for(int i = 0;i<vec.size();i++)
    {
        countArr[vec[i]]++;
    }

    vec.clear();
    for(int i = 0;i<=maxx;i++)
    {
        while(countArr[i])
        {
            vec.push_back(i);
            countArr[i]--;
        }
    }

    delete[] countArr;
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
    CountSort(vec);
    print(vec);
}