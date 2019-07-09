#include <iostream>
#include <vector>
using namespace std;

class MyAndCheck
{
public:
    int find_set(int x)
    {
        //带路径优化的并查集查找算法
        int i,j,r;
        r = x;
        while(_set[r]!=r)
        {
            //寻找此集合的代表，即根节点
            r = _set[r];
        }
        i = x;
        while(i != r)
        {
            //路径压缩
            //使得r代表的集合中，即所有子节点直接指向根节点
            j = _set[i];
            _set[i] = r;
            i = j;
        }
        return r;
    }
    void union_set(int x,int y)
    {
        //x,y分属不同的集合，则将两个集合合并
        int t = find_set(x);
        int h = find_set(y);

        if(t<h){
            _set[h]=t;
        }
        else {
            _set[t]=h;
        }
    }
    int *getSet()
    {
        return _set;
    }
private:
    int _set[10001];
};

class MyFriends
{
public:
    int friends(int n,int m, vector<vector<int>> r)
    {
        int i,count;
        for(i=1;i<=n;++i)
        {//n是森林中所有的节点数目
            _andCheck.getSet()[i] = i;
        }
        for(i=0;i<m;++i)
        {//m是关系数目
            _andCheck.union_set(r[i][0],r[i][1]);
        }
        count = 0;
        for(i = 1;i<=n;++i)
        {
            if(_andCheck.getSet()[i]==i)
            {
                //统计根节点个数,即朋友圈总数
                ++count;
            }
        }
        return count;
    }
private:
    MyAndCheck _andCheck; 
};

int main()
{
    MyFriends myFriends;

    int count ;
    vector<vector<int>> relation ={{1,2},{2,3},{4,5}};
    count =  myFriends.friends(5,3,relation);
    cout<<count<<endl;
}
