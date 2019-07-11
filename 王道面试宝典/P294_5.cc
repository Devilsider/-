#include <iostream>
#include <vector>
#define M 100
#define N 100
using namespace std;

bool FindElem(int arr[M][N],int elem)
{
    int row = 0;
    int col = N - 1;
    while(row<M&&col>=0)
    {
        if(arr[row][col]==elem)
        {
            return true;
        }
        if(arr[row][col]>elem)
        {
            --col;
        }else{
            ++row;
        }
    }
    return false;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

