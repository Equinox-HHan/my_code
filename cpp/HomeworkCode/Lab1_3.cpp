#include<iostream>
using namespace std;

int main(){
    int number;
    int remainder;
    int number_positive;
    
    cout<<"please enter a number"<<endl;
    cin>>number;
    if(number==0)
        cout<<"0"<<endl;
    else{
        if(number>0){
            for(number;number>=2;number%2){
                remainder=number%2;
                number=number/2;
                cout<<remainder<<endl;}
        }
        else{
            number_positive=number*(-1);
            for(number_positive;number_positive>=2;number_positive%2){
                remainder=number_positive%2;
                number_positive=number_positive/2;
                cout<<remainder<<endl;}
        }
    }
      return 0;
}     
            
      

