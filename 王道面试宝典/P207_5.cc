#include <iostream>
typedef struct node LinkNode;
struct node{
    int data;
    LinkNode *next;
};
LinkNode * reverse_link_recursive(LinkNode *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    
    LinkNode *curr,*reverse_head,*temp; 

    if(head->next==NULL)
    {
        return head;
    }else {
        curr = head;
        temp = head->next;//temp为(a2,...an)的头指针
        reverse_head = reverse_link_recursive(temp);
        temp->next = curr;
        curr->next =NULL;
    } 
    return reverse_head;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

