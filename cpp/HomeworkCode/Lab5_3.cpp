#include<bits/stdc++.h>
using namespace std;

class Complex
{
	public:
	Complex(float real_number=0.0,float img_number=0.0);//构造函数
	Complex(const Complex &p);//浅复制构造函数
	
	void setNumber(float r_number,float i_number)
	{
		real=r_number;
		img=i_number;
	}	
	void showNumber()
	{
		cout<<"show the number";
		if(img>0)
		{
			cout<<real<<"+"<<img<<"i"<<endl;
		}
		else if(img<0)
		{
			cout<<real<<"-"<<img<<"i"<<endl;
		}
		else
		{
			cout<<real<<endl;
		}
	}
	float getReal()
	{
		return real;
	}
	float getImg()
	{
		return img;
	}
	void isEqualNumber(Complex num1,Complex num2)
	{
		if((num1.getReal()==num2.getReal())&&(num1.getImg()==num2.getImg()))
		{
			cout<<"is equal number"<<endl;
		}
		else
		{
			cout<<"not equal numbers"<<endl;
		}
	}
	void addNumber(Complex num1,Complex num2)
	{
		float realNum=num1.getReal()+num2.getReal();
		float imgNum=num1.getImg()+num2.getImg();
		cout<<"the added number is: ";
		cout<<realNum<<"+"<<imgNum<<"i"<<endl;
	}
	
	private:
		float real;
		float img;
};

Complex::Complex(float real_number,float img_number)
{
	real=real_number;
	img=img_number;
}
Complex::Complex(const Complex&p)
{
	real=p.real;
	img=p.img;
}

int main()
{
	Complex number1,number2;
	cout<<"please change the number: enter two number"<<endl;
	float r_number;float i_number;
	cin>>r_number>>i_number;
	number2.setNumber(r_number,i_number);
	number2.showNumber();
	number2.isEqualNumber(number1,number2);
	number1=number2;
	number2.isEqualNumber(number1,number2);
	number2.addNumber(number1,number2);
	return 0;
}
