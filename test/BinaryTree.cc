#include <stdlib.h>

#include <iostream>
#include <stack>
using namespace std;

struct BinaryTreeNode
{
    int _data;
    struct BinaryTreeNode * _lchild;
    struct BinaryTreeNode * _rchild;
};

void PreOrder(BinaryTreeNode* head)
{
    if(head==NULL)
    {
        return ;
    }
    BinaryTreeNode* p = head;
    stack<BinaryTreeNode*> s;
    while(p||!s.empty())
    {
        if(p)
        {
            cout<<p->_data<<" ";
            s.push(p);
            p = p->_lchild;
        }else {
            p = s.top();
            p = p->_rchild;
            s.pop();
        }
    }
    cout<<endl;
}
void InOrder(BinaryTreeNode* head)
{
    if(head==NULL)
    {
        return;
    }
    BinaryTreeNode* p = head;
    stack<BinaryTreeNode*> s;
    while(p||!s.empty())
    {
        if(p)
        {
            s.push(p);
            p= p->_lchild;
        }else{
            p = s.top();
            cout<<p->_data<<" ";
            p = p->_rchild;
            s.pop();
        }
    }
    cout<<endl;
}

void PostOrder(BinaryTreeNode* head)
{
    if(head==NULL)
    {
        return;
    }
    BinaryTreeNode* p =head,*r=NULL;
    stack<BinaryTreeNode*> s;
    while(p||!s.empty())
    {
        if(p)
        {
            s.push(p);
            p = p->_lchild;
        }else {
            p = s.top();
            if(p->_rchild&&p->_rchild!=r)
            {
                p = p->_rchild;
                s.push(p);
                p = p->_lchild;
            }else{
                p = s.top();
                cout<<p->_data<<" ";
                s.pop();
                r = p;
                p =NULL;
            }
        }
    }
}
bool isEqual(BinaryTreeNode* head1,BinaryTreeNode* head2)
{
    if(head1==NULL&&head2==NULL)
    {
        return true;
    }
    if(!head1||!head2)
    {
        return false;
    }
    if(head1->_data==head2->_data)
    {
        return (isEqual(head1->_lchild,head2->_lchild)&&isEqual(head1->_rchild,head2->_rchild))||
                (isEqual(head1->_lchild,head2->_rchild)&&isEqual(head1->_rchild,head2->_lchild));
    }
    else {
        return false;
    }
}

struct RESULT
{//定义返回结果
    int nMaxDistance;//最大距离
    int nMaxDepth;//最大深度
};
RESULT GetMaximumDistance(BinaryTreeNode* head)
{
    if(!head)
    {
        RESULT empty={0,-1};//最大深度初始化为-1，因为调用者要对其加1，然后变为0
        return empty;
    }
    RESULT lhs = GetMaximumDistance(head->_lchild);
    RESULT rhs = GetMaximumDistance(head->_rchild);
    RESULT result;
    result.nMaxDepth = max(lhs.nMaxDepth+1,rhs.nMaxDepth+1);
    result.nMaxDistance = max(max(lhs.nMaxDistance,rhs.nMaxDistance),
                              lhs.nMaxDepth+rhs.nMaxDepth+2);
    return result;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

