#include<bits/stdc++.h>
using namespace std;

class Animal
{
    public:
        virtual void shout()=0; 
        virtual ~Animal()
        {
            cout<<"destruction function of animal"<<endl;
        }
};
class Cat:public Animal
{
    public:
        void shout()
        {
            cout<<"Cat"<<endl;
        }
        virtual ~Cat()
        {
            cout<<"destruction function of cat"<<endl;
        }
};
class Dog:public Animal
{
    public:
        void shout()
        {
            cout<<"Dog"<<endl;
        }
        virtual ~Dog()
        {
            cout<<"destruction function of dog"<<endl;
        }
};
class Sheep:public Animal
{
    public:
        void shout()
        {
            cout<<"Sheep"<<endl;
        }
        virtual ~Sheep()
        {
            cout<<"destruction function of sheep"<<endl;
        }
};

int main()
{
    Cat cat;
    Dog dog;
    Sheep sheep;
    Animal* arr[3];
    arr[0]=new Cat;
    arr[1]=new Dog;
    arr[2]=new Sheep;
    for(int i=0;i<3;i++)
    {
        arr[i]->shout();
    }
    for(int i=0;i<3;i++)
    {
        delete arr[i];
    }
    return 0;
}