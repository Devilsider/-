#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class andCheck
{
public:
    andCheck(size_t size)
    :_set(size,0) 
    {}
    void find_set(T x)
    {
        T i,j,r;
        r = x;
        while(_set[r]!= r)
        {
            r = _set[r];
        }
        i = x;
        while(i != x)
        {
            j=_set[i];
            _set[i] = r;
            i = j;
        }
        return r;//返回集合代表，即根节点
    }
    void union_set(T x,T y)
    {
        int t = find_set(x);
        int h = find_set(y);
        if(t<h){
            _set[h] = t;
        }
        else {
            _set[t] = h;
        }
    }
    int friends(int n,int m ,vector<int> &r)
    {
        int i,count;
        
    }
private:
    vector<T> _set;
};

