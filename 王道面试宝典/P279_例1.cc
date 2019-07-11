#include <iostream>
#include <map>
#include <vector>
using namespace std;

class SuffixTreeNode
{
public:
    SuffixTreeNode(){}
    //递归插入一个后缀子字符串，原理同trie树的插入，s为要插入的字符串
    //index为s在主串中的起始位置
    void insertString(const string &s,int index)
    {
        _indexes.push_back(index);
        if(s.length()>0)
        {
            _value = s[0];
            SuffixTreeNode* child = NULL;
            if(_children.find(_value)!=_children.end())
            {
                //如果首字符节点已经存在
                child = _children[_value];
            }else {
                //若不存在
                child = new SuffixTreeNode();
                _children[_value] = child;
            }
            string remainder = s.substr(1);//保存除首元素之外的子串
            child->insertString(remainder,index);//递归插入
        }
    }
    //用递归法查询子串，原理同trie树
    vector<int> getIndexes(const string &s)
    {
        if(s.length()==0)
        {
            return _indexes;
        }else {
            char first = s[0];
            if(_children.find(first)!=_children.end())
            {
                string remainder = s.substr(1);
                return _children[first]->getIndexes(remainder);
            }else{
                vector<int> empty;
                return empty;
            }
        }
    }
    ~SuffixTreeNode()
    {
        map<char,SuffixTreeNode*>::iterator ite;
        for(ite = _children.begin();ite!=_children.end();++ite)
        {
            delete (ite->second);
        }
    }
private:
    map<char,SuffixTreeNode*> _children;
    char _value;//节点的字符值
    vector<int> _indexes;//存储子字符串在s中开始的位置
};
class SuffixTree
{
public:
    SuffixTree(const string &s)
    {
        _root = new SuffixTreeNode();
        for(int i=0;i<static_cast<int>(s.length());++i)
        {
            string suffix = s.substr(i);
            _root->insertString(suffix,i);
        }
    }
    vector<int> getIndexes(const string &s)
    {
        return _root->getIndexes(s);
    }
    ~SuffixTree()
    {
        if(_root!=NULL)
        {
            delete _root;
        }
    }
private:
    SuffixTreeNode* _root;
};
int main()
{
    string testString = "mississippi" ;
    string stringList[]={"is","sip","hi","sis"};
    SuffixTree tree{testString};
    for(int i=0;i<4;++i)
    {
        vector<int> li = tree.getIndexes(stringList[i]);
        if(li.size()!=0)
        {
            cout<<stringList[i].c_str()<<" ";
            for(int j=0;j<static_cast<int>(li.size());++j)
            {
                cout<<li[j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

