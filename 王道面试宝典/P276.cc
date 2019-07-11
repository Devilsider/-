#include <string.h>

#include <iostream>
#include <vector>
using namespace std;
const int branchNum = 26;//生命常量，英文字符的基
struct Trie_node{
    bool isStr;//记录此处是否构成一个串
    Trie_node *next[branchNum];//指向各个子树的指针
    Trie_node()
    :isStr(false)
    {
        bzero(next,sizeof(next));
    }
};
class Trie
{
public:
    Trie()
    {
        _root = new Trie_node();
    }
    void insert(const char* word);
    bool search(char *word);
    void deleteTrie(Trie_node *root);
    Trie_node* getTrie()
    {
        return _root;
    }
private:
    Trie_node* _root; 
};
//插入一个单词
void Trie::insert(const char* word)
{
    Trie_node *location = _root;
    while(*word)
    {
        if(location->next[*word-'a']==NULL)
        {
            //不存在则建立一个新节点
            Trie_node *tmp = new Trie_node();
            location->next[*word - 'a']=tmp;
        }
        location=location->next[*word-'a'];
        //每插入一步，相当于有一个新串经过，指针向下移动
        ++word;
    }
    location->isStr = true;
}
//在trie树上进行查找的过程为：从根节点出发，沿和给定的值逐层下降，
//若达到给定的值的尾部的时候，且此节点的标记isStr为true，则成功
//若节点中和给定的值对应的指针为空，或者到达给定值尾部的时候，节点
//中的标记为false，则查找不成功
bool Trie::search(char *word)
{
    Trie_node* location = _root;
    while(*word&&location)
    {
        location = location->next[*word - 'a'];
        ++word;
    }
    return (location!=NULL&&location->isStr);
}
//销毁键树
void Trie::deleteTrie(Trie_node *_root)
{
    for(int i=0;i<branchNum;++i)
    {
        if(_root->next[i]!=NULL){
            deleteTrie(_root->next[i]);
        }
    }
    delete _root;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

