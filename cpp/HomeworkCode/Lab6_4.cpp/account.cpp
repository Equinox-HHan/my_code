#include<bits/stdc++.h>
#include"account.h"
using namespace std;

double SavingAccount::Total=0;
SavingAccount::SavingAccount(int date,int id,double rate)
{
	lastDate=date; ID=id; Rate=rate;
	Balance=0; Accumulation=0;
	cout<<"Account: #"<<getID()<<" created!"<<endl;
}
int SavingAccount::getID() const
{
	return ID;
}
double SavingAccount::getBalance() const
{
	return Balance;
}
double SavingAccount::getRate() const
{
	return Rate;
}
void SavingAccount::show() const
{
	cout<<"#ID: "<<getID()<<"---Balance: "<<getBalance()<<endl;
}

double SavingAccount::deposit(int date,double amount)
{
	return record(date,amount);
	void show();
}
double SavingAccount::withdraw(int date,double amount)
{
	if(amount>getBalance())
	{
		cout<<"--No Enough Money--ERROR"<<endl;
	}
	else
	{
		record(date,-amount);
		void show();
	}
}
int SavingAccount::settle(int date)
{
	double interest=accumulate(date)*Rate/360;
	if(interest!=0)
	{
		record(date,interest);	
	}
	Accumulation=0; 
}

