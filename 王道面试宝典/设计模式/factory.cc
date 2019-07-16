#include <iostream>
using namespace std;
//简单工厂模式
class Product
{
public:
    virtual ~Product() {}
    virtual void operation()=0;
};

class ProductA:public Product
{
public:
    void operation(){
        cout<<"ProductA::operation()"<<endl;
    }
};
class ProductB:public Product
{
    void operation()
    {
        cout<<"ProductB::operation()"<<endl;
    }
};
class ProductC:public Product
{
    void operation()
    {
        cout<<"ProductC::operation()"<<endl;
    }
};

class factory
{
public:
    Product* createProduct(char product)
    {
        Product* ap = NULL;
        switch(product)
        {
        case 'A':
            ap = new ProductA;
            break;
        case 'B':
            ap = new ProductB;
            break;
        case 'C':
            ap = new ProductC;
            break;
        }
        return ap;
    }
};

int main()
{
    factory * f =new factory();
    Product * ap = f->createProduct('A') ;
    ap->operation();
    
    ap = f->createProduct('B');
    ap->operation();
    
    ap = f->createProduct('C');
    ap->operation();

    delete ap;
    delete f;
    return 0;
}

