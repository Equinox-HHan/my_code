#include<bits/stdc++.h>
using namespace std;
bool twoSameNumber(int number)
{
    int a[10]={0};
    for(int i=0;i<=2;i++)
    {
        a[number%10]++;
        number/=10;
    }
    for(int j=0;j<10;j++)
    {
        if(a[j]==2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}
void numberProduceFun(int &originalMoney)
{      
    int input=100;
    originalMoney-=input;
    int number;int winAmount;
    
    number = rand() % 900+100;
    if(number==888)
    {
        winAmount=input*10;
        originalMoney+=winAmount;
        cout<<number<<" "<<"win"<<" "<<originalMoney<<endl;
        system("pause");
    }
    else if(number==111||number==222||number==333||number==444||number==555||number==666||number==777||number==999)
    {
        winAmount=input*5;
        originalMoney+=winAmount;
        cout<<number<<" "<<"win"<<" "<<originalMoney<<endl;
        system("pause");
    }
    
    else if(twoSameNumber(number))
    {
        winAmount=input*1;
        originalMoney+=winAmount;
        cout<<number<<" "<<"win"<<" "<<originalMoney<<endl;
        system("pause");
    }
    
    else
    {   
        cout<<number<<" "<<"lose"<<" "<<originalMoney<<endl;
        system("pause");
    }
    
    
    return;
}

int main()
{   
    int originalMoney=1000;int input=100;
    srand((unsigned) time(NULL));
    for(int n=1;n<=10;n++)
    {
        numberProduceFun(originalMoney);
    }
    return 0;
}
