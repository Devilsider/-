#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main()
{
    int i;
    for(i=0;i<2;++i)
    {
        fork();
        /* printf("-"); */
        printf("-\n");
    }
    return 0;
}

