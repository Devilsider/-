#include <iostream>

int main()
{
    int w[3][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    int (*p)[4] = w;

    for(int idx= 0;idx<3;++idx)
    {
        for(int jdx= 0;jdx<4;++jdx)
        {
            std::cout<<p[idx][jdx]<<std::endl;
        }
    }

    int m,n;
    int **a = new int *[m];
    for(int i=0;i<m;++i){
        a[i]=new int [n]; 
    }

    return 0;
}

