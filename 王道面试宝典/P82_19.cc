#include <iostream>
#include <vector>
using namespace std;

int func(vector<int> vec)
{
    cout<<"----------func--------"<<endl;
    static int k =2;
    vector<int>::reverse_iterator it;
    for(it = vec.rbegin();it!=vec.rend();++it)
    {
        k+=*it%2==0?++*it:(*it)++;//语句一
    }
    for(auto &i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"----------func--------"<<endl;
    return k;
}
int main()
{
    vector<int> vec;
    for(int i =0;i<4;++i)
    {
        vec.push_back(i);
        printf("%d ",func(vec));
    }
    return 0;
}

