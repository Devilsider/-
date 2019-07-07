#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class MyQueue
{
public:
    MyQueue(){}
    int size()
    {
        return _s1.size()+_s2.size();
    }
    bool empty()
    {
        if(size()==0)
        {
            return true;
        }else{
            return false;
        }
    }
    void push(T value)
    {
        _s1.push(value);
    }
    T front()
    {
        if(!_s2.empty())
        {
            return _s2.top();
        }
        while(!_s1.empty())
        {
            _s2.push(_s1.top());
            _s1.pop();
        }
        return _s2.top();
    }
    void pop()
    {
        if(_s2.empty())
        {
            while(!_s1.empty())
            {
                _s2.push(_s1.top());
                _s1.pop();
            }
        }
        _s2.pop();
    }
private:
    stack<T> _s1,_s2;
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

