#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int  strToInt(const char *str)
{
    long long num = 0;
    if(str!=NULL)
    {
        const char * digit = str;
        bool minus = false;
        if(*digit == '+')
        {
            ++digit;
        }else if(*digit == '-')
        {
            ++digit;
            minus = true;
        }
        while(*digit != '\0')
        {
            if(*digit >'0'&&*digit <'9')
            {
                num = num*10 +(*digit - '0');
                if(num>std::numeric_limits<int>::max())
                {
                    num = 0;
                    break;
                }
                ++digit;
            }
            else {
                num = 0;
                break;
            }
        }
        if(*digit == '\0')
        {
            if(minus)
            {
                num = 0 - num;
            }
        }
    }
    return num;
}
string  intToString(int num)
{
    int numC = num;
    bool minus = false;
    string res;    
    if(numC<0)
    {
        numC = -numC;
        minus = true;
    }
    while(numC>0)
    {//这是逆序的，从个位往高位求
        char n = numC%10 + '0';
        res = res + n;
        numC = numC/10;
    }
    if(minus)
    {
        res = res + '-';
    }
    reverse(begin(res),end(res));

    return res;
}
int main()
{    
    char p[]="12345678";
    int i1 = 12345678;
    int i2 = -12345678;

    int temp = strToInt(p);
    cout<<temp<<endl;
    string s1 = intToString(i1);
    string s2 = intToString(i2);
    cout<<s1<<endl;
    cout<<s2<<endl;
    
    return 0;
}

