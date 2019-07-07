#include <iostream>
#include <string>
using namespace std;
class MyDist
{
public:
    int calDistance(const string &str1,const string &str2)
    {
        if(str1.empty())
        {
            return str2.size();
        }
        if(str2.empty())
        {
            return str1.size();
        }
        int len1 = static_cast<int>(str1.size())+1;
        int len2 = static_cast<int>(str2.size())+1;

        int matrix[len1][len2];
        for(int idx = 0;idx<len1;++idx)
        {
            matrix[idx][0]=idx;
        }
        for(int idx = 0;idx<len2;++idx)
        {
            matrix[0][idx]=idx;
        }
        for(int i =1;i<len1;++i)
        {
            for(int j =1;j<len2;++j)
            {
                int func = (str1[i-1]==str2[j-1])?0:1;
                matrix[i][j] = minOfThree(matrix[i-1][j]+1,matrix[i][j-1]+1,matrix[i-1][j-1]+func);
            }
        }
        for(int i=0;i<len1;++i)
        {
            for(int j=0;j<len2;++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

        return matrix[len1-1][len2-1];
    }
    int minOfThree(int a,int b ,int c)
    {
        int min = a>b?b:a;
        min = min>c?c:min;
        return min;
    }
};
int main()
{
    string s1("ace");
    string s2("abcdef");
    
    MyDist dis;
    int res = dis.calDistance(s1,s2);
    cout<<res<<endl;
    return 0;
}

