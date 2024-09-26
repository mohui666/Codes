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

void BucketSort(vector<int>& vec)
{
    //时间复杂度（快排/归并）：O(N+C)  C=(n*(logn-logm)) m为桶的数量
    //空间复杂度（快排）：O(N+M); N：桶空间 M：排序空间
    //稳定性：取决于所选择的排序

    int maxx = *max_element(vec.begin(),vec.end());
    int minx = *min_element(vec.begin(),vec.end());
    int bucketNum=(maxx-minx+1)/vec.size()+1;
    vector<vector<int>> Buckets(bucketNum);
    for(int i = 0;i<vec.size();i++)
    {
        int index = (vec[i]-minx+1)/vec.size();
        Buckets[index].push_back(vec[i]);
    }
    for(int i = 0;i<Buckets.size();i++)
    {
        sort(Buckets[i].begin(),Buckets[i].end());
    }

    vec.clear();
    for(int i = 0;i<Buckets.size();i++)
    {
        for(int j = 0;j<Buckets[i].size();j++)
        {
            vec.push_back(Buckets[i][j]);
        }
    }
}

void BuildMaxHeap(vector<int>& vec,int start,int end)
{
    int cur = start;
    int l = 2*cur + 1;
    for(;l<=end;cur=l,l = 2*cur + 1)
    {
        if(l<end&&vec[l]<vec[l+1])
        {
            l++;
        }
        if(vec[l]>vec[cur])
        {
            swap(vec[l],vec[cur]);
        }
        else
        {
            break;
        }
    }

}

void HeapSort(vector<int>& vec)
{
    //时间复杂度：O(nlogn)
    //空间复杂度：O(1)
    //稳定性：不稳定
    for(int i = vec.size()/2-1;i>=0;i--)
    {
        BuildMaxHeap(vec,i,vec.size()-1);
    }
    for(int i = vec.size()-1;i>0;i--)
    {
        swap(vec[0],vec[i]);
        BuildMaxHeap(vec,0,i-1);
    }
}

void QuickSort(vector<int>& vec,int l,int r)
{
    //时间复杂度：O(nlogn)
    //空间复杂度：O(logn)
    //稳定性：不稳定
    if(l>=r)
    {
        return;
    }
    int tmp = vec[l];
    int i = l,j=r;
    while(i<j)
    {
        while(i<j&&vec[j]>tmp)
        {
            j--;
        }
        if(i<j)
        {
            vec[i] = vec[j];
            i++;
        }
        while(i<j&&vec[i]<tmp)
        {
            i++;
        }
        if(i<j)
        {
            vec[j] = vec[i];
            j--;
        }
    }
    vec[i]=tmp;
    QuickSort(vec,l,i-1);
    QuickSort(vec,i+1,r);
}

void MergeSort(vector<int>& vec,int l,int mid,int r)
{ 
    //时间复杂度：O(nlogn)
    //空间复杂度：O(nlogn)
    //稳定性：稳定
    int *tmp = new int[r-l+1];
    int i = l,j=mid+1,index=0;
    while(i<=mid&&j<=r)
    {
        if(vec[i]<=vec[j])
        {
            tmp[index++]=vec[i++];
        }
        else
        {
            tmp[index++]=vec[j++];
        }
        
    }
    while(i<=mid)
    {
        tmp[index++] = vec[i++];
    }
    while(j<=r)
    {
        tmp[index++] = vec[j++];
    }
    for(int i = 0;i<index;i++)
    {
        vec[l+i] = tmp[i];
    }
    delete[] tmp;
}

void Merge_up2down(vector<int>& vec,int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int mid =(l+r)/2;
    Merge_up2down(vec,l,mid);
    Merge_up2down(vec,mid+1,r);
    MergeSort(vec,l,mid,r);
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
    vector<int> vec {1,4,5,6,8,7,3,9,2,165,848,154,57,41,415,64,87,87,88,481,1,7,87,7,8,77,15,78,95,451,3,564,87,54,641,34,678,94,561,234,5678,6};
    Merge_up2down(vec,0,vec.size()-1);
    print(vec);
}