#include<iostream>
using namespace std;

//给出数据类型
const float PI=3.141593;
const float FENCE_PRICE=35;
const float CONCRETE_PRICE=20;

//编写circle类
class Circle{
public:
    Circle(float r);    //构造函数
    float circumference();   //成员函数计算周长
    float area();   //成员函数计算面积
private:
    float radius;   //圆的半径
};

//类的实现
//构造函数初始化成员数据radius
Circle::Circle(float r){
    radius=r;
}

//计算圆的周长
float Circle::area(){
    return PI*2*radius;
}

//计算圆的面积
float Circle::circumference(){
    return PI*radius*radius;
}

//主函数的实现
int main(){
    float radius;
    cout<<"Enter the radius of the circle:"<<endl;
    cin>>radius;

    Circle pool(radius); //创建Circle类的对象poll
    Circle poolRim(radius+3);

    //计算栅栏造价并输出
    float fenceCost=poolRim.circumference()*FENCE_PRICE;
    cout<<"The cost of the fence is $"<<fenceCost<<endl;

    //计算过道造价并输出
    float concreteCost=(poolRim.area()-pool.area())*CONCRETE_PRICE;
    cout<<"Concreate cost is$"<<concreteCost<<endl;

    return 0;
}

