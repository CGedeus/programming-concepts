#include <iostream>

class parent
{
    public:
     virtual void virtualFunctionTest()
     {
         std::cout << "This is a virtual function." << std::endl;
     }

    public:
     void simpleFunction()
     {
         std::cout << "This is a simple function in parent class." << std::endl;
     }
};

class child : public parent
{
    public:
     void virtualFunctionTest() 
     {
         std::cout << "This is a virtual function in the CHILD CLASS." << std::endl;
     }

    public:
     void simpleFunction()
     {
        std::cout << "This is a simple function in parent class." << std::endl;
     }
};

int main(void)
{
    parent *p0;
    child c0;

    p0 = &c0;

    p0->virtualFunctionTest();
    p0->simpleFunction();
    return 0;
}