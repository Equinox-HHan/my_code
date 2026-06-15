#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
	public:
		BankAccount(int id,double rate,int date);//¹¹Ôìº¯Êý 
		
		void getID()
		{
			cout<<"ID:#"<<ID<<endl;	
		}
		double getBalance()
		{
			return Balance;
		}
		double getRate()
		{
			return Rate;
		}
		void cash_in(int date,double amount)
		{
			record(date,amount);
		}
		void cash_out(int date,double amount)
		{
			if(amount>getBalance())
			{
				cout<<"no enough money!"<<endl;
			}
			else
			{
				record(date,-amount); 
			}
		}
		double calculateAccumulation(int date)
		{
			return Accumulation+Balance*(date-lastDate);
		} 
		void show()
		{
			cout<<"ID: #"<<ID<<" balance: "<<Balance;
		}
		
	private:
		int ID;
		double Balance;
		double Rate;
		int lastDate;
		double Accumulation;
		void record(int date,double amount)
		{
			cout<<Balance<<". record: "<<amount<<endl;
			Accumulation=calculateAccumulation(date);
			lastDate=date;
			amount=floor(amount*100+0.5)/100;
			Balance+=amount;
			show();
		}
		void calculateRate(int date)
		{
			double interest=calculateAccumulation(date)*Rate/360;
			if(interest!=0)
			{
				record(date,interest);	
			} 
			Accumulation=0;
		}
		
};
BankAccount::BankAccount(int id,double rate,int date)
{
	ID=id;
	Rate=rate;
	lastDate=date;
	Balance=0;
	Accumulation=0;
}

int main()
{
	BankAccount user(254001064,0.03,1);
	user.cash_in(10,5000);
	user.cash_out(20,2000);
	user.calculateAccumulation(360);
	user.show();
	return 0;
}
