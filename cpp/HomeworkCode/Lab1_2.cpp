#include<iostream>
using namespace std;

int main(){
    int x=1;
    int y=1;
    for(;x<=9;x++){
        for(y=1;y<=x;y++){
            cout<<x<<"*"<<y<<"="<<x*y<<"\t";
        }
        cout<<endl;
    }
    return 0;
}