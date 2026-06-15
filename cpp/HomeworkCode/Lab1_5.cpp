#include<bits/stdc++.h>
using namespace std;
//是否是五位数
bool isFiveDIgit(int number){
    if(number >= 10000 && number <= 99999)
    {
        return true;
    } 
    else
    {
        return false;
    }
}
//是否是不重复的五位数
bool isValidNumber(int number){
    string numstr = to_string(number);
    numstr[0]='a';
    numstr[1]='b';
    numstr[2]='c';
    numstr[3]='d';
    numstr[4]='e';
    if(numstr[0]!=numstr[1]&&numstr[0]!=numstr[2]&&numstr[0]!=numstr[3]&&numstr[0]!=numstr[4]&&
       numstr[1]!=numstr[2]&&numstr[1]!=numstr[3]&&numstr[1]!=numstr[4]&&
       numstr[2]!=numstr[3]&&numstr[2]!=numstr[4]&&
       numstr[3]!=numstr[4])
    {
        return true;
    } 
    else 
    {
        return false;
    }
} 
int reverseNumber(int number){
    int reversed = 0;
    while (number>0)
    {
        reversed=reversed*10+number%10;
        number/=10;
    }
    return reversed;
}

int main(){
    int number;
    int reversedNumber;
    int mutiplyer;
    cout<<"寻找符合 ABCDE * ? = EDCBA 的算式："<<endl;
    cout<<"其中ABCDE是各位数字都不相同的5位数"<<endl;
    for(number=10000;number<=99999;number++)
    {
        if(!isFiveDIgit(number))
        {
            cout<<"不是五位数"<<endl;
            continue;
        }
        if (!isValidNumber(number))
        {
            cout<<"不是不重复的五位数"<<endl;
            continue;
        }
        reversedNumber=reverseNumber(number);
        if(reversedNumber%number==0){
            mutiplyer=reversedNumber/number;
            if(mutiplyer>=1&&mutiplyer<=9){
                cout<<number<<" * "<<mutiplyer<<" = "<<reversedNumber<<endl;
            }
            else{
                cout<<"乘数不是1-9的数"<<endl;
            }
        }
    }
    return 0;                                                                           
}


