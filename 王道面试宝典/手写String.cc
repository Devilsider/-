#include <string.h>

#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class MyString
{
public:
    MyString()
    :_data( new char[1]())
    {
        cout<<"MyString()"<<endl;
        *_data = '\0';
    }
    MyString(const char * str)
    :_data(new char[strlen(str)+1]())
    {
        cout<<"MyString(const char * str)"<<endl;
        strcpy(_data,str);
    }
    MyString(const MyString &rhs)
    :_data(new char[rhs.size()+1]())
    {
        //复制构造函数，深拷贝
        cout<<"MyString(const MyString &rhs)"<<endl;
        strcpy(_data,rhs.c_str());
    }
    MyString(MyString && str)
    :_data(new char[str.size()+1]())
    {
        cout<<"MyString(MyString&&str)"<<endl;
    }
    ~MyString()
    {
        cout<<"~MyString"<<endl;
            delete []_data;
    }
    MyString &operator=(const MyString &rhs)
    {
        //赋值构造函数
        if(&rhs!=this){
            delete []_data;
            _data = new char[strlen(rhs.c_str()+1)]();
            strcpy(_data,rhs.c_str());
        }
        return *this;
        
    }
    MyString &operator=(MyString &&rhs)
    {
        if(&rhs!=this){
            delete []_data;
            _data = new char[strlen(rhs.c_str()+1)]();
            strcpy(_data,rhs.c_str());
        }
        return *this;
    }
    

    size_t size()const 
    {
        return strlen(_data);
    }
    const char * c_str()const 
    {
        return _data;
    }
private:
    char *_data;
};


//测试用例
void foo(MyString x){}
void bar(const MyString &x){}
MyString baz()
{
    MyString ret("world");
    return ret;
}
int main()
{
    
    MyString s0; 
    MyString s1("hello"); 
    MyString s2(s0); 
    MyString s3=s1; 
    s2 = s1;
    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    MyString s4 = baz();

    std::vector<MyString> vec;
    vec.push_back(s0);
    vec.push_back(s1);
    vec.push_back(baz());
    vec.push_back("goodjob");
    return 0;
}

