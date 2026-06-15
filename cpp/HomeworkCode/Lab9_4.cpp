#include<bits/stdc++.h>
using namespace std;

class Shape
{
	public:
		Shape()
		{
			cout<<"Construction Function of Shape"<<endl;	
		}
		~Shape()
		{
			cout<<"Distruction Function of Shape"<<endl;
		}
		void Show()
		{
			cout<<"---Shape---"<<endl;
		}
		void setNumber()
		{
			int number;
			cout<<"enter a number"<<endl;
			cin>>number;
			cout<<number<<endl;	
		} 
};

class Circle:virtual public Shape
{
	public:
		Circle(int r=0)
		{
			this->r=r;
			cout<<"Construction Function of Circle"<<endl;
		}
		~Circle()
		{
			cout<<"Distruction Function of Circle"<<endl;
		}
		void getR()
		{
			cout<<"enter R"<<endl;
			cin>>r;
		}
		void show()
		{
			cout<<"---Circle---"<<endl;
		}
		double getArea()
		{
			return pi*r*r;
		}
		double getRound()
		{
			return pi*2*r;
		}
		
	protected:
		double r;
		const double pi=3.14;
};


class Rectangle:virtual public Shape
{
	public:
		Rectangle(int x=0,int y=0)
		{
			this->x=x;
			this->y=y; 
			cout<<"Construction Function of Rectangle"<<endl;
		}
		~Rectangle()
		{
			cout<<"Distruction Function of Rectangle"<<endl;
		}
		void show()
		{
			cout<<"---Rectangle---"<<endl;
		}
		void getXY()
		{
			cout<<"enter X Y"<<endl;
			cin>>x>>y;
		}
		double getArea()
		{
			return x*y;
		}
		double getRound()
		{
			return (x+y)*2;
		}
		
	protected:
		double x,y;
};

class Square:public Rectangle
{
	public:
		Square(int c=0):Rectangle(c,c)
		{
			cout<<"Construction Function of Square"<<endl;
		}
		~Square()
		{
			cout<<"Distruction Function of Square"<<endl;
		}
		void show()
		{
			cout<<"---Square---"<<endl;
		}
		void getXY()
		{
			cout<<"enter a number"<<endl;
			cin>>x;
			y=x;
		}
};

int main()
{
	Shape shape;
	Circle circle;
	Rectangle rectangle;
	Square square;
	
	shape.Shape::Show();
	square.setNumber();//直接访问虚基类成员函数square.Shape::setNumber()也是正确语法 
	cout<<endl;
	
	circle.show();
	circle.Circle::getR();
	cout<<"area--"<<circle.Circle::getArea()<<endl;
	cout<<"round--"<<circle.Circle::getRound()<<endl;
	cout<<endl;
	
	cout<<endl; 
	square.Square::show();//square.show()同名直接调用派生类函数也是正确语法;
	square.getXY();
	cout<<"area--"<<square.getArea()<<endl;
	cout<<"round--"<<square.getRound()<<endl;
	cout<<endl;
	
	rectangle.show();
	rectangle.getXY();
	cout<<"area--"<<square.Rectangle::getArea()<<endl;//通过::符号由sqare访问rectangle类成员 
	cout<<"round--"<<square.Rectangle::getRound()<<endl;
	
	return 0;
}
