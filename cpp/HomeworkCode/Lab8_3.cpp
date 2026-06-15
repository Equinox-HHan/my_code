#include<bits/stdc++.h> 
using namespace std;

class Point
{
	public:
		Point(int xx=0,int yy=0)
		{
			x=xx;
			y=yy;
			cout<<"Consturctor Function called"<<endl;	
		}	
		Point(const Point &p)
		{
			x=p.x;
			y=p.y;
			cout<<"shallow copy Function"<<endl; 
		}
		~Point()
		{
			cout<<"Destructor Function called"<<endl;
		}
		
		int getX() const
		{
			return x;
		}
		int getY() const
		{
			return y;
		}
		void setNUmber(int x,int y)
		{
			this->x=x;
			this->y=y;
		}
		
	private:
		int x;
		int y;
};

class ArrayofPoints
{
	public:
		ArrayofPoints(int size)
		{	
			this->size=size;
			pointer=new Point[size];
			cout<<"Construct Function"<<endl;
		}
		ArrayofPoints(const ArrayofPoints &m)
		{
			size=m.size;
			pointer=new Point[size];
			for(int i=0;i<size;i++)
			{	
				pointer[i]=m.pointer[i]	;
			}	
		}
		~ArrayofPoints()
		{
			delete[] pointer;
			cout<<"Destruct Function called"<<endl;
		}
		Point &element(int index)
		{
			assert(index>=0&&index<size);
			return pointer[index];	
		} 
	
	private:
		int size;
		Point *pointer; 
};

int main()
{
	cout<<"Please enter the count of points"<<endl;
	int count;
	cin>>count;
	ArrayofPoints pointsArray1(count); 
	pointsArray1.element(0).setNUmber(5,10);
	pointsArray1.element(1).setNUmber(15,20);
	
	ArrayofPoints pointsArray2=pointsArray1;
	cout<<"copy of point array1"<<endl;
	cout<<"point 0 of arr2"<<pointsArray2.element(0).getX()<<" "
	<<pointsArray2.element(0).getY()<<endl;
	cout<<"point 1 of arr2"<<pointsArray2.element(1).getX()<<" "
	<<pointsArray2.element(1).getY()<<endl;
	
	pointsArray1.element(0).setNUmber(25,30);
	pointsArray1.element(1).setNUmber(35,40);
	cout<<"after changing pointsArray1"<<endl;
	cout<<"point 0 of arr2"<<pointsArray2.element(0).getX()<<" "
	<<pointsArray2.element(0).getY()<<endl;
	cout<<"point 1 of arr2"<<pointsArray2.element(1).getX()<<" "
	<<pointsArray2.element(1).getY()<<endl;
	
	return 0;
}
