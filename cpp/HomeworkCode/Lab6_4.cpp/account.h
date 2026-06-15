#include<bits/stdc++.h>

class SavingAccount
{
	public:
		SavingAccount(int date,int id,double rate);
		
		int getID() const;
		double getBalance() const;
		double getRate() const;
		void show() const;
		
		double deposit(int date,double amount);
		double withdraw(int date,double amount);
		int settle(int date);
		
		static double getTotal()
		{
			return Total;
		}
		
	private:
		int ID;
		double Balance;
		double Rate;
		int lastDate;
		double Accumulation;
		
		static double Total;
		
		double record(int date,double amount)
		{
			Accumulation=accumulate(date);
			lastDate=date;
			amount=floor(amount*100+0.5)/100;
			Balance+=amount;
			Total+=amount;
		}
		double accumulate(int date) const
		{
			return Accumulation+Balance*(date-lastDate);
		}
};
