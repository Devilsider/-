#include <iostream>
#include <vector>
using namespace std;
class MyBitMap
{
    enum{
        SHIFT = 5,
        MASK = 0x1f,
        BITS_PER_INT = 32,
    };
public:
        MyBitMap(unsigned int range)
        :_data(1+range/BITS_PER_INT)
        {}
        void set(unsigned int number)
        {
            _data[number>>SHIFT] |= (1<<(number&MASK));
        }
        void reset(unsigned int number)
        {
            _data[number>>SHIFT] &= (~(1<<(number&MASK)));
        }
        bool test(unsigned int number)
        {
            return _data[number>>SHIFT]&(1<<(number&MASK));
        }
private:
        vector<unsigned int> _data;
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

