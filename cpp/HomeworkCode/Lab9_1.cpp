#include<bits/stdc++.h>
using namespace std;

struct Info
{
	string Name;
	string Address;
	string City;
	int Number;
};

class Employee
{
	public:
		Employee(string name="No",string address="No",string city="No",int number=000000)
		{
			in.Name=name;
			in.Address=address;
			in.City=city;
			in.Number=number;
		}
		Employee(const Employee &m)
		{
			in.Name=m.in.Name;
			in.Address=m.in.Address;
			in.City=m.in.Address;
			in.Number=m.in.Number;
		}
		Info setInfomation()
		{
			cout<<"please enter name,address,city and number:"<<endl;	
			cin>>in.Name;
			cin>>in.Address;
			cin>>in.City;
			cin>>in.Number;
			return in;
		} 
		void display()
		{
			cout<<"Name: "<<in.Name<<endl;
			cout<<"Address: "<<in.Address<<endl;
			cout<<"City: "<<in.City<<endl;
			cout<<"number: "<<in.Number<<endl;
		}
		
		private:
			Info in;
};

int main()
{
	Info in;
	Employee person1;
	person1.setInfomation();
	person1.display();
	return 0;
}
