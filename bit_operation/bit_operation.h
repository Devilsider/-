#ifndef __BIT_OPERATION_H__
#define __BIT_OPERATION_H__

class Bit
{
public:

    Bit() 
    {}
    ~Bit() {}
    
    bool isOddNum(const int & intenger){
        if((intenger&1)==1){
            //位运算 取最低位是否为1
            return true;
        }
        return false;
    }

    void swap(int &num1,int &num2){
        //位运算交换两数
        num1=num1^num2;
        num2=num1^num2;
        num1=num2^num1;
    }

    int changeSign(int &num1){
        //改变数的符号 取反加一
       return (~num1+1);
    }

    int pow(int base, int power){
        //位运算求base的power次方
        //将指数拆解,是时间复杂度由o(n^2)下降到o(log(n))
        int sum=1;
        int n=power;
        int temp=base;
        while(n!=0){
            if((n&1)==1){
                sum*=temp;
            }
            temp*=temp;
            n=n>>1;
        }
        return sum;
    }

    unsigned int findN(unsigned int n){
        //找出不大于n的最大的二次幂数
        //移位求或,例如n为01010011 ,那么数就是01000000
        //若是32位最高位为1要判断，否则溢出
        if(n>=2147483648){
            return 2147483648;
        }
        for(int idx=0;idx<32;++idx){
            n|=n>>(idx+1);
        }
        return (n+1)>>1;
    }

private:
};

#endif
