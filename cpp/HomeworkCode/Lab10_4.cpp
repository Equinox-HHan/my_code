#include <iostream>
using namespace std;

class Animals
{
public:
    Animals() { cout << "Animals constructor" << endl; }
    virtual void show()
    {
        cout << "Animals" << endl;
    }
    virtual ~Animals() { cout << "Animals destructor" << endl; }
};

class Dog : public Animals
{
public:
    Dog() { cout << "Dog constructor" << endl; }
    virtual void show() override
    {
        cout << "Dog" << endl;
    }
    virtual ~Dog() override { cout << "Dog destructor" << endl; }
};

class Cat : public Animals
{
public:
    Cat() { cout << "Cat constructor" << endl; }
    virtual void show() override
    {
        cout << "cat" << endl;
    }
    virtual ~Cat() override { cout << "Cat destructor" << endl; }
};

void func(Animals* ptr)
{
    ptr->show();
}

int main()
{
    
    Animals* arr[3];
    arr[0] = new Animals(); 
    arr[1] = new Dog();     
    arr[2] = new Cat();      
    
    for(int i = 0; i < 3; i++)
    {
        func(arr[i]);
    }
    for(int i = 0; i < 3; i++)
    {
        delete arr[i];
    }
    
    return 0;
}