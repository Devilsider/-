#include <iostream>
#include <pthread.h>
#include <stdlib.h>
using namespace std;
class Singleton
{
public:
    class AutoRelease
    {
    public:
        AutoRelease(){}
        ~AutoRelease()
        {
            if(_pInstance)
            {
                delete _pInstance;
            }
        }
    };
    static Singleton * getInstance()
    {
        if(_pInstance==NULL)
        {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }
    void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }
private:
    Singleton(){}
    ~Singleton(){}
private:
    static Singleton * _pInstance;
    static AutoRelease _autoRelease;
};
Singleton * Singleton::_pInstance = NULL;
Singleton::AutoRelease Singleton::_autoRelease;


class Singleton2
{
public:
    static Singleton2* getpInstance()
    {
        if(_pInstance==NULL)
        {
            _pInstance = new Singleton2();
            atexit(destroy);
        }
        return _pInstance;
    }
    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }
private:
    Singleton2(){}
    ~Singleton2(){}
private:
    static Singleton2* _pInstance;
};
Singleton2* Singleton2::_pInstance = Singleton2::getpInstance();


class Singleton3
{
public:
    static Singleton3* getInstance()
    {
        pthread_once(&_once,init);
        return _pInstance;
    }
    static void init()
    {
        _pInstance = new Singleton3();
        atexit(destroy);
    }
    static void destroy()
    {
        if(_pInstance){
            delete _pInstance;
        }
    }
private:
    Singleton3(){}
    ~Singleton3(){}
private:
    static Singleton3* _pInstance;
    static pthread_once_t _once;
};
Singleton3* Singleton3::_pInstance = NULL;
pthread_once_t Singleton3::_once = PTHREAD_ONCE_INIT;
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

