#include <iostream>
using namespace std;
struct list_node
{
    int data;
    list_node *next;
};

class MyEntrance
{
public:
    list_node * FindBeginning(list_node* head)
    {
        list_node *n1=head;
        list_node *n2=head;

        while(n2->next != NULL)
        {
            //寻找相遇点
            n1 = n1->next;
            n2 = n2->next->next;
            if(n1 == n2)
            {
                break;
            }
        }
        //没有相遇，因为没有环
        if(n2->next == NULL)
        {
            return NULL;
        }
        //将n1从head开始移动，n2从相遇点处移动
        n1 = head;
        while(n1 != n2)
        {
            n1=n1->next;
            n2=n2->next;
        }
        return n2;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

