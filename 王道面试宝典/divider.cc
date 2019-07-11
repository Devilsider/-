#include <iostream>
#include <string>
#include <vector>
using namespace std;

int divider(char *input_string,char div)
{
    string srcStr(input_string);
    vector<string> vec;
    if(srcStr.empty())
    {
        return -1;
    }
    int pre=0,cur=0;
    int len = static_cast<int>(srcStr.size());

    while(cur<len&&pre<len)
    {
        while(cur<len&&srcStr[cur]!=div)
        {
            ++cur;
        }
        string tmp = srcStr.substr(pre,cur-pre);
        vec.push_back(tmp);
        while(cur<len&&srcStr[cur]==div)
        {
            ++cur;
        }
        pre = cur;
    }
    for(auto &i:vec)
    {
        cout<<i<<endl;
    }
    return 0;
}

int main()
{
    char str[] = "tplink---2018---06--04" ;
    int ret = divider(str,'-');

    cout<<ret<<endl;
    return 0;
}

