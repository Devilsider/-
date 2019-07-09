#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node{
    int value;
    struct Node *pLeft;
    struct Node *pRight;
};
struct RESULT{
    int nMaxDistance;
    int nMaxDepth;
};
RESULT GetMaximumDistance(Node *root)
{
    if(!root){
        RESULT empty = {0,-1};//最大深度初始化为-1，是因为调用者要对其加1，然后变为0
        return empty;
    }
    RESULT lhs = GetMaximumDistance(root->pLeft);
    RESULT rhs = GetMaximumDistance(root->pRight);
    RESULT result;
    result.nMaxDepth = max(lhs.nMaxDepth+1,rhs.nMaxDepth+1);
    result.nMaxDistance = max(max(lhs.nMaxDistance,rhs.nMaxDistance),lhs.nMaxDepth+rhs.nMaxDepth+2);
    return result;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

