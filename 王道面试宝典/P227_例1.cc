#include <iostream>
using namespace std;
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
bool IsBalanced(BinaryTreeNode* pRoot,int* pDepth)
{
    if(pRoot == NULL)
    {
        *pDepth = 0;
        return true;
    }
    int left,right;
    if(IsBalanced(pRoot->m_pLeft,&left)&&IsBalanced(pRoot->m_pRight,&right))
    {
        int diff = left - right;
        if(diff<=1&&diff>=-1)
        {
            *pDepth = 1+(left>right?left:right);
            return true;
        }
    }
    return false;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

