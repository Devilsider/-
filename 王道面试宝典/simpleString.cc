#include <string.h>
#include <string>
#include <utility>
using namespace std;
class String
{
public:
    String()
    :_data(new char[1]())
    {
        _data[0]='\0';
    }
    String(const char* str)
    :_data(new char[strlen(str)+1]()) 
    {
        strcpy(_data,str);
    }
    String(const String &str)
    :_data(new char[str.size()+1]())
    {
        strcpy(_data,str.c_str());
    }
    ~String()
    {
        delete []_data;
    }
    String& operator=(String rhs)
    {
        swap(rhs);
        return *this;
    }
    String(String &&rhs)
    :_data(new char[rhs.size()+1]())
    {
        rhs._data= NULL;
    }

    String& operator=(String &&rhs)
    {
        swap(rhs);
        return *this;
    }
    size_t size()const
    {
        return strlen(_data);
    }
    const char * c_str()const
    {
        return _data;
    }
    void swap(String &rhs)
    {
        std::swap(_data,rhs._data);
    }
private:
    char *_data;
};

