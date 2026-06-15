#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    int number;
    int money=1000;
    int chance=10;
    char answer;
    int i;
    srand((unsigned)time(NULL));
    for(i=1;i<=10;i++)
    {
        cout<<"please enter 'b' or 's'"<<endl;
        cout<<"you have"<<money<<" yuan,"<<chance<<" chance"<<endl;
        
        number=rand()%100+1;
        cin>>answer;
        if(number>=50&&number<=100)
        {
            if(answer=='b')
            {
                money+=100;
                chance--;
                cout<<"you win! the number is "<<number<<endl;
                cout<<"you have"<<money<<" yuan,"<<chance<<" chance"<<endl;
            }
            else if(answer=='s')
            {
                money-=100;
                chance--;
                cout<<"you lose! the number is "<<number<<endl;
                cout<<"you have"<<money<<" yuan,"<<chance<<" chance"<<endl;
            }
        }
        else if(number>=1&&number<50)
        {
            if(answer=='s')
            {
                money+=100;
                chance--;
                cout<<"you win! the number is "<<number<<endl;
                cout<<"you have"<<money<<" yuan,"<<chance<<" chance"<<endl;
            }
            else if(answer=='b')
            {
                money-=100;
                chance--;
                cout<<"you lose! the number is "<<number<<endl;
                cout<<"you have"<<money<<" yuan,"<<chance<<" chance"<<endl;
            }
        }
    }
    return 0;
}