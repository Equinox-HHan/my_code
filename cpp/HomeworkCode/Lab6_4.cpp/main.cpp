#include<bits/stdc++.h>
#include"account.h"
using namespace std;
int main()
{
	SavingAccount User1(1,20325302,0.015);
	SavingAccount User2(1,58320212,0.015);
	cout<<endl;
	User1.deposit(10,2000);
	User2.deposit(10,5000);
	User1.withdraw(17,1000);
	User2.withdraw(17,10000);
	cout<<endl;
	User1.settle(20);
	User2.settle(20);
	cout<<endl;
	User1.show(); 
	User2.show(); 
	cout<<endl;
	cout<<"--TOTAL: "<<SavingAccount::getTotal()<<endl;  
	
	return 0;
}
