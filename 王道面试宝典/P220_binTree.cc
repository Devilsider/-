#include <iostream>
#include <stack>
using namespace std;
//后序遍历
struct BiTreeNode
{
    int data;
    BiTreeNode *lchind;
    BiTreeNode *rchind;

};
void preOrder(BiTreeNode* T)
{
    stack<BiTreeNode*> s;
    BiTreeNode *p = T;
    while(p||!s.empty())
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            s.push(p);
            p = p->lchind;
        }else {
            BiTreeNode *temp = s.top();
            p = temp->rchind;
            s.pop();
        }
    }
}
void inOrder(BiTreeNode *T)
{
    stack<BiTreeNode*> s;
    BiTreeNode *p = T;
    while(p||!s.empty())
    {
        if(p)
        {
            s.push(p);
            p = p->lchind;
        }else{
            BiTreeNode *temp = s.top();
            cout<<temp->data<<" ";
            p = temp->rchind;
            s.pop();
        }
    }
}
void PostOred(BiTreeNode* T)
{
    stack<BiTreeNode*> s;
    BiTreeNode * p = T,*r = NULL,temp;
    while(p||!s.empty())
    {
        if(p){
            s.push(p);
            p = p->lchind;
        }else {
            p = s.top();
            if(p->rchind&&p->rchind!=r)
            {
                p = p->rchind;
                s.push(p);
                p = p->lchind;
            }else{
                p = s.top();
                s.pop();
                cout<<p->data;
                r = p;
                p = NULL;
            }
        }
    }
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

