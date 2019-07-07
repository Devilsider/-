#include <iostream>
#include <string>
using namespace std;

class MyLCS
{
public:
    size_t LCS(const string &str1,const string &str2)
    {
        if(str1.empty()||str2.empty())
        {
            return 0;
        }
        int len1 = static_cast<int>(str1.size());
        int len2 = static_cast<int>(str2.size());
        
        int matrix[len1][len2];
        for(int idx = 0 ;idx<len2;++idx)
        {
            matrix[0][idx] = 0;
        }
        for(int idx = 0 ;idx<len1;++idx)
        {
            matrix[idx][0] = 0;
        }

        for(int i = 1;i<len1;++i)
        {
            for(int j=1;j<len2;++j)
            {
                if(str1[i]==str2[j])
                {
                    matrix[i][j]=matrix[i-1][j-1]+1;
                }else {
                    matrix[i][j]= (matrix[i][j-1]>matrix[i-1][j])?matrix[i][j-1]:matrix[i-1][j];
                }
            }
        }
        return matrix[len1-1][len2-1];
    }
};
int main()
{
    MyLCS lcs;
    string s1("hello word");
    string s2("wordhello ");
    int len = lcs.LCS(s1,s2);

    cout<<len<<endl;
    return 0;
}

