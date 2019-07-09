#include <iostream>
#include <exception>
using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode * m_pLeft;
    BinaryTreeNode * m_pRight;
};
BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,
                              int *startInorder,int* endInorder);
BinaryTreeNode* Construct(int *preorder,int *inorder,int length)
{
    if(preorder==NULL||inorder==NULL||length<0)
    {
        return NULL;
    }
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}
BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,
                              int *startInorder,int* endInorder)
{
    //前序遍历序列的第一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();//建立节点
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight =NULL;
    if(startPreorder == endPreorder){
        //边界条件
        if(startInorder == endInorder && *startPreorder == *startInorder)
        {
            return root;
        }
        else 
        {
            cout<<"Invalid input."<<endl;
            return NULL;
        }
    }
    //在中序遍历中找根节点的值
    int* rootInorder = startInorder;
    while(rootInorder<=endInorder && *rootInorder!=rootValue)
    {
        ++rootInorder;
    }
    if(rootInorder==endInorder&&*rootInorder!=rootValue)
    {
            cout<<"Invalid input."<<endl;
            return NULL;
    }
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder+leftLength;
    if(leftLength>0)
    {
        //构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1,leftPreorderEnd,
                                      startInorder,rootInorder - 1);
    }
    if(leftLength<endPreorder - startPreorder)
    {
        //构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd+1,endPreorder,
                                       rootInorder + 1,endInorder);
    }
    return root;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

