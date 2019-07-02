#include <iostream>
using namespace std;
struct s3{
    char c;
    int i;
};
struct s4
{
    char c1;
    s3 s;
    char c2;
};

int main()
{
    s3 s;
    s.c ='c';
    s.i =1;
    cout<<&s.c<<endl;
    cout<<&s.i<<endl;
    cout<<sizeof(s3)<<endl;
    cout<<sizeof(s4)<<endl;
    return 0;
}

