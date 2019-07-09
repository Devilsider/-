#include <iostream>
#include <stack>
using namespace std;
struct SBinaryTreeNode{
    int m_nValue;//value of node
    SBinaryTreeNode *m_pLeft;//left child of node
    SBinaryTreeNode *m_pRight;//right child of node
};
int tree_height(SBinaryTreeNode *head)
{
    SBinaryTreeNode *p=head,*r=NULL;
    stack<SBinaryTreeNode*> s;
    int height  = 0; 
    while(p||!s.empty())
    {
        if(p)
        {
            s.push(p);
            p=p->m_pLeft;
        }
        else {
            p = s.top();
            if(p->m_pRight&&p->m_pRight!=r)
            {
                p=p->m_pRight;
                s.push(p);
                p=p->m_pLeft;
            }else {
                height = (height > static_cast<int>(s.size()))?height:static_cast<int>(s.size());
                p = s.top();
                s.pop();
                r = p;
                p =NULL;
            }
        }
    }
    return height;
}
int tree_height_recursive(SBinaryTreeNode *head)
{
    int left,right;
    if(head == NULL)
    {
        return -1;
    }
    else {
        left = tree_height_recursive(head->m_pLeft)+1;
        right = tree_height_recursive(head->m_pRight)+1;
        return (left>right)?left:right;
    }
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

