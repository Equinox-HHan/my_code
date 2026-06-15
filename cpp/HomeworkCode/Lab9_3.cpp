#include<bits/stdc++.h> 
using namespace std;

class Point
{
	public:
		Point()
		{	
			cout<<"Construction Function of Point"<<endl;	
		}
		~Point()
		{
			cout<<"Distruction Function of Point"<<endl;
		}
	
	protected:
		const double  pi=3.14;
	    int x,y; 
};

class Circle:public Point
{
	public:
		Circle()
		{
			cout<<"Construction Function of Circle"<<endl; 
		}
		~Circle()
		{
			cout<<"Distruction Function of Circle"<<endl;
		}
		void inrformation()
		{
			cout<<"enter a number"<<endl;
			cin>>r;
			cout<<pi*r*r<<endl;
		}
		
	protected:
		int r;
		const double pi=3.14;
};

class Cylinder:public Circle
{
	public:
		Cylinder()
		{
			cout<<"Construction Function of Cylinder"<<endl;
		}
	
		~Cylinder()
		{
			cout<<"Distruction Function of Cylinder"<<endl;
		}
		int setR()
		{
			cout<<"enter a number as r"<<endl;
			cin>>r;
		}
		int setH()
		{
			cout<<"enter a number as h"<<endl;
			cin>>h;
		}
		int geth()
		{
			return h;
		}
		void show()
		{
			cout<<pi*h*r*r<<endl;
		}
	
	private:
		int h;
		
};

int main()
{
	Cylinder c;
	c.setR();
	c.setH();
	c.show();
	
	Circle circle;
	circle.inrformation();
	
	return 0;
}
