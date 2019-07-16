#include <iostream>
#include <stack>
using namespace std;
struct BiTreeNode
{
    int data;
    BiTreeNode* lchild;
    BiTreeNode* rchild;
};
void PreOrder(BiTreeNode* head)
{
    if(NULL==head)
    {
        return;
    }
    BiTreeNode* p = head;
    stack<BiTreeNode*> s;
    while(p||!s.empty())
    {
        if(p)
        {
            cout<<p->data<<endl;
            s.push(p);
            p=p->lchild;
        }else{
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}
void InOrder(BiTreeNode* head)
{
    if(head==NULL)
    {
        return;
    }
    BiTreeNode* p = head;
    stack<BiTreeNode*> s;
    while(p||!s.empty())
    {
        if(p)
        {
            s.push(p);
            p=p->lchild;
        }else{
            p = s.top();
            cout<<p->data<<endl;
            s.pop();
            cout<<p->data<<endl;
            p = p->rchild;
        }
    }
}
void PostOrder(BiTreeNode* head)
{
    if(head==NULL)
    {
        return ;
    }
    BiTreeNode *p,*r=NULL;
    stack<BiTreeNode*> s;
    while(p||!s.empty())
    {
        if(p)
        {
            s.push(p);
            p = p->lchild;
        }else {
            p = s.top();
            if(p->rchild&&r!=p->rchild)
            {
                p = p->rchild;
                s.push(p);
                p = p->lchild;
            }else {
                p = s.top();
                s.pop();
                cout<<p->data<<endl;
                r = p;
                p =NULL;
            }
        }
    }
}
bool isEqual(BiTreeNode* head1,BiTreeNode* head2)
{
    if(head1==NULL&&head2==NULL){
        return true;
    }
    if(!head1||!head2)
    {
        return false;
    }
    if(head1->data==head2->data)
    {
        return (isEqual(head1->lchild,head2->lchild)&&isEqual(head1->rchild,head2->rchild))||
                (isEqual(head1->rchild,head2->lchild)&&isEqual(head1->lchild,head2->rchild));
    }
    else 
    {
        return false;
    }
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

