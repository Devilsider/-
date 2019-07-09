#include <iostream>
using namespace std;
struct BinaryNode{
    int m_iValue;
    BinaryNode *m_pLeft;
    BinaryNode *m_pReft;
};
bool _isEqual(BinaryNode* node1,BinaryNode* node2)
{
    if(node1==NULL&&node2==NULL)
    {
        return 1;
    }
    if(!node1||!node2)
    {
        return 0;
    }
    if(node1->m_iValue==node2->m_iValue)
    {
        return _isEqual(node1->m_pLeft,node2->m_pLeft)&&
            _isEqual(node1->m_pReft,node2->m_pReft);
    }
    else return 0;
}
bool _isEqual2(BinaryNode* node1,BinaryNode* node2)
{
    if(node1==NULL&&node2==NULL)
    {
        return 1;
    }
    if(!node1||!node2)
    {
        return 0;
    }
    if(node1->m_iValue==node2->m_iValue)
    {
        return (_isEqual2(node1->m_pLeft,node2->m_pLeft)&&
            _isEqual2(node1->m_pReft,node2->m_pReft))||
            (_isEqual2(node1->m_pLeft,node2->m_pReft)&&
            _isEqual2(node1->m_pReft,node2->m_pLeft));
    }
    else return 0;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

