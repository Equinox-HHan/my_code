#include<iostream>
using namespace std;
int main()
{
    cout<<"hou much points did you get in the exam?"<<endl;
    int points;
    cin>>points;
    if(points<60)
        cout<<"failed"<<endl;
    else
    {
        if(points>=60&&points<=79)
            cout<<"middle"<<endl;
        else if(points>=80&&points<=89)
            cout<<"good"<<endl;
        else
            cout<<"excellent"<<endl;
    }    
    return 0;   
}