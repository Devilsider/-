#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class MyHeap
{
public:
    void heapify(int start,int end,vector<T> &arr)
    {
         int dad = start;
         int son = dad*2+1;

         while(son<end)
         {
             if(son+1<=end&&arr[son]<arr[son+1])
             {
                 ++son;
             }
             if(arr[dad]>=arr[son])
             {
                 return ;
             }
             else
             {
                swap(arr[dad],arr[son]);
                dad = son;
                son = dad*2+1;
             }
         }
    }
    void heapSort(vector<T> &arr)
    {
        int len = static_cast<int>(arr.size());
        for(int idx = len/2-1;idx>=0;--idx)
        {
            heapify(idx,len,arr);
        }
        for(int idx = len-1;idx>0;--idx)
        {
            swap(arr[0],arr[idx]);
            heapify(0,idx-1,arr);
        }
    }
};

template <typename T>
class MyQuickSort
{
public:
    void quickSort(int start,int end,vector<T> &arr)
    {
        if(start>=end)
        {
            return;
        }
        int left = start;
        int right = end;
        int pivot = arr[left];
        while(left<right)
        {
            while(left<right&&arr[right]>=pivot)
            {
                --right;
            }
            while(left<right&&arr[left]<=pivot)
            {
                ++left;
            }
            if(right>left)
            {
                swap(arr[left],arr[right]);
            }
        }
        arr[start] = arr[left];
        arr[left] = pivot;
        quickSort(start,left-1,arr);
        quickSort(left+1,end,arr);
        return;
    }
};
template<typename T>
class MySelectSort
{
public:
    void selectSort(vector<T> &arr)
    {
        for(auto iter = arr.begin();iter!=arr.end();++iter) 
        {
            for(auto iter2 = iter;iter2!=arr.end();++iter2)
            {
                if(*iter>*iter2)
                {
                    swap(*iter,*iter2);
                }
            }
        }
    }
};

template<typename T>
class MyShell
{
public:
    void shellSort(vector<T> &arr)
    {
        int gap,i,j;
        int len = static_cast<int>(arr.size());
        int temp;
        for(gap = len>>1;gap>0;gap>>=1)
        {
            for(i=gap;i<len;++i)
            {
                temp = arr[i];
                for(j=i-gap;j>=0&&arr[j]>temp;j-=gap)
                {
                    arr[j+gap] = arr[j];
                }
                arr[j+gap] = temp;
            }
        }
    }
};

template<typename T> 
class MyBubble
{
public:
    void bubbleSort(vector<T>& arr)
    {
       for(auto iter = arr.begin();iter!=arr.end();++iter)
       {
           for(auto iter2 = arr.begin();iter2!=arr.end()-distance(arr.begin(),iter);++iter2)
           {
               if(*iter2>*(iter2+1))
               {
                   swap(*iter2,*(iter2+1));
               }
           }
       }
    }
};

template<typename T>
class MyInsertSort
{
public:
    void insertSort(vector<T> &arr)
    {
        int i,j,key;
        int len = static_cast<int>(arr.size());
        for(i=1;i<len;++i)
        {
            key = arr[i];
            for(j=i-1;j>=0&&arr[j]>=key;--j)
            {
                arr[j+1]=arr[j];
            }
            arr[j+1] = key;
        }
    }
};

template<typename T> 
class MyMergeSort
{
public:
    void mergeSort_recursive(int start,int end,vector<T> &arr,vector<T> &res)
    {
        if(start>=end)
        {
            return;
        }
        int len = end - start,mid = len/2 +start;
        int start1 = start,end1 = mid;
        int start2 = mid+1,end2 = end;
        mergeSort_recursive(start1,end1,arr,res);
        mergeSort_recursive(start2,end2,arr,res);

        int k = start;
        while(start1<=end1&&start2<=end2)
        {
            res[k++] = (arr[start1]<arr[start2])?arr[start1++]:arr[start2++];
        }
        while(start1<=end1)
        {
            res[k++] = arr[start1++];
        }
        while(start2<=end2)
        {
            res[k++] = arr[start2++];
        }
        for(k=start;k<=end;++k)
        {
            arr[k] = res[k];
        }
    }
    void mergeSort(vector<T> &arr)
    {
        vector<T> res(arr.size());
        int len = static_cast<int>(arr.size());
        mergeSort_recursive(0,len-1,arr,res);
    }
};
class MyCount
{
public:
    void countingSort(vector<int> &arr,vector<int> &res,int range)
    {
        vector<int> count_arr(range,0);
        int len = static_cast<int>(arr.size());
        for(int i = 0;i<len;++i)
        {
            ++count_arr[arr[i]];
        }
        for(int i =1;i<range;++i)
        {
            count_arr[i]+=count_arr[i-1];
        }
        for(int i = len;i>0;--i)
        {
            res[--count_arr[arr[i-1]]] = arr[i-1];
        }
    }
};
int main()
{
    vector<int> arr = {1,2323,4,232,5,6643,354,54,234,64356,865,657,432,234};
    
    vector<int> res(arr.size());
    MyCount mc;
    mc.countingSort(arr,res,65535);

    for(auto &i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

