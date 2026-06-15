#include<bits/stdc++.h>
using namespace std;

class Oval
{
	public:
		Oval(double lr=0,double sr=0)
		{
			cout<<"Construction Function of Oval"<<endl;
			Lr=lr;
			Sr=sr;
		}	
		Oval(const Oval &p)
		{
			cout<<"Copy Function of Oval"<<endl;
			Lr=p.Lr;
			Sr=p.Sr;
		}
		void setR()
		{
			cout<<"please enter the number of longR and shortR"<<endl;
			cin>>Lr>>Sr;
		}
		double getLr()
		{
			cout<<"Lr is: "<<Lr<<endl;
			return Lr;
		}
		double getSr()
		{
			cout<<"Sr is: "<<Sr<<endl;
			return Sr;
		}
		void calculateArea()
		{
			cout<<pi*getLr()*getSr()<<endl; 
		}
		~Oval()
		{
			cout<<"Distruction Function of Oval"<<endl;
		}
		
		protected:
			const double pi=3.14;
			double Lr,Sr,Area; 
};

class Circle:public Oval
{
	public:
		Circle(double r=0):Oval(r,r)
		{
			cout<<"Construction Function of Circle"<<endl;
		}
		Circle(const Circle &c):Oval(c)
		{
			cout<<"Copy Function of Circle"<<endl;
		}
		void setR()
		{
			cout<<"please enter r"<<endl;
			double r;
			cin>>r;
			Lr=r;
			Sr=r; 
		}
		~Circle()
		{
			cout<<"Distruction Function of Circle"<<endl;
		}
		
};

int main()
{
	Circle member;
	Oval member1;
	member1.setR();
	member1.calculateArea();
	member.setR();
	member.calculateArea();
	return 0;
}
