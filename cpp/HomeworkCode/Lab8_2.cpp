#include<bits/stdc++.h>
using namespace std;

class Circle
{
	public:
		Circle(double radiu=0,int x=0,int y=0)
		{
			r=radiu;
			this->x=x;
			this->y=y;
		}
		Circle(const Circle &p)
		{
			r=p.r; 
			x=p.x;
			y=p.y; 
		}
		
		double getR()
		{
			return r;
		}
		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}
		
		double *calculate() 
		{
			static double arr[2];
			arr[0]=pi*2*r;
			arr[1]=pi*r*r;
			return &arr[0];
		}
		void setCircle(double r,int xx,int yy)
		{
			this->r=r;
			x=xx;
			y=yy;
		}
		void showCircle()
		{ 
			double *arr=calculate(); 
			cout<<"Point:"<<"("<<getX()<<","<<getY()<<")"<<endl;
			cout<<"Radiu:"<<getR()<<endl; 
			cout<<"Area:"<<*arr<<endl;			
			cout<<"Perimeter:"<<*(arr+1)<<endl;
		}
		
	private:
		int x;int y;
		double r;
		const double pi=3.14;
};

int main()
{
	vector<Circle> vec(10);
	cout<<"Enter a number"<<endl;
	int n;cin>>n;
	cout<<"Enter infomation"<<endl;
	for(int i=0;i<n;i++)
	{
		int arr[3]={0};
		cin>>arr[0]>>arr[1]>>arr[2];
		vec[i].setCircle(arr[0],arr[1],arr[2]);
		vec[i].showCircle();
		cout<<endl;
	} 
	return 0;
}
