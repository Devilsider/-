#pragma once
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using namespace std;
class Singleton1
{
public:
    static Singleton1 *getInstance()
    {
        if(_pInstance==NULL) 
        {
            _pInstance = new Singleton1();
            atexit(destroy);
        }
        return _pInstance;
    }

    static void destroy()
    {
        if(_pInstance)
        {
            delete []_pInstance;
        }
    }
private:
    Singleton1(){}
    ~Singleton1(){}
private:
    static Singleton1* _pInstance;
};
Singleton1 * Singleton1::_pInstance = Singleton1::getInstance();

class Singleton2
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
    Singleton2 *getInstance()
    {
        if(_pInstance==NULL)
        {
            _pInstance = new Singleton2();
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
    Singleton2(){}
    ~Singleton2(){}
private:
    static Singleton2 * _pInstance;
    static AutoRelease _autoRelease;
};
Singleton2* Singleton2::_pInstance = NULL;
Singleton2::AutoRelease Singleton2::_autoRelease;

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
        if(_pInstance==NULL)
        {
            _pInstance = new Singleton3();
            atexit(destroy);
        }
    }
    static void destroy()
    {
        if(_pInstance)
        {
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
