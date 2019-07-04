#include <iostream>
using namespace std;
unsigned int FindFirstBitIs1(int num)
{
    int temp = num;
    int indexBit =0;
    indexBit = temp & (-temp) ;
    return indexBit;
}

bool isBit1(int num,unsigned int indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}

void FindNumsAppearOnce(int data[],int length,int &num1,int &num2)
{
    if(length<2)
    {
        return ;
    }
    int resultExclusiveOR = 0;
    for(int i = 0;i<length;++i)
    {
        resultExclusiveOR ^= data[i];
    }
    
    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
    num1 = num2 =0;   
    for(int j=0;j<length;++j)
    {
        //将元数组分为两组，第indexof1位为1的为一组，为0的为另外一组
        if(isBit1(data[j],indexOf1))
        {
            num1 ^= data[j];
        }else {
            num2 ^= data[j];
        }
    }
}

int main()
{
    int arr[10] ={1,1,2,2,3,3,4,4,5,6};
    int num1,num2;
    FindNumsAppearOnce(arr,10,num1,num2);
    cout<<num1<<" "<<num2<<endl;
    return 0;
}

