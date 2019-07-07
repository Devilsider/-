#include <iostream>
using namespace std;

struct Tnode
{
    int value;
    Tnode *next;
};
Tnode *unique(Tnode *head)
{
    if(head==NULL||head->next==head)
    {
        return head;
    }
    Tnode *pre,*cur;
    pre = head;
    cur = head->next;
    while(cur != head)
    {
        while(pre->value==cur->value&&cur!=head)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        if(cur==head){
            break;
        }
        pre=cur;
        cur=cur->next;
    }
    if(pre->value==cur->value)
    {
        pre->next=cur->next;
        free(cur);
        pre=pre->next;
        return pre;
    }
    else {
        return cur;
    }
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

