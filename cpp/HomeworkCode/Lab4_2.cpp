#include<bits/stdc++.h>
using namespace std;

class Swimming_Pool1//方形游泳池
{
    public:
    Swimming_Pool1(float len,float wid);//构造函数声明
    Swimming_Pool1(Swimming_Pool1 &p);//复制构造函数声明

    float area(float len,float wid)//计算游泳池面积
    {
        return len*wid;
    }
    float road_size(float len,float wid)//计算过道面积
    {
        return (len+2)*(wid+2)-len*wid;
    }
    float fence(float len,float wid)//计算栅栏长度
    {
        return 2*(len+wid);
    }

    private:
    float length,width;
};

Swimming_Pool1::Swimming_Pool1(float len=0,float wid=0)//构造函数的实现
{
    length=len;
    width=wid;
}
Swimming_Pool1::Swimming_Pool1(Swimming_Pool1&p)//复制构造函数的实现
{
    length=p.length;
    width=p.width;
}

class Swimming_Pool2//设计圆形游泳池
{
    public:
    
    Swimming_Pool2(float r);//构造函数声明
    Swimming_Pool2(Swimming_Pool2 &p);//复制构造函数声明

    float area(float r)//计算游泳池面积
    {
        return PI*r*r;
    }
    float road_size(float r)//计算过道面积
    {
        return PI*(r+1)*(r+1)-PI*r*r;
    }
    float fence(float r)//计算栅栏长度
    {
        return 2*PI*r;
    }
    
    private:
    const float PI=3.141593;
    float radius;
};

Swimming_Pool2::Swimming_Pool2(float r=0)//构造函数的实现
{
    radius=r;
}
Swimming_Pool2::Swimming_Pool2(Swimming_Pool2 &p)//复制构造函数的实现
{
    radius=p.radius;
}

int main()
{   float prize_size,prize_fence;
    cout<<"enter the prize_size and prize_fence:"<<endl;
    cin>>prize_size>>prize_fence;
    cout<<"enter lenth and width for rectangular swimming pool:"<<endl;
    float len,wid;
    cin>>len>>wid;
    Swimming_Pool1 pool1; //创建方形游泳池对象pool1
    float prize_of_size1=(pool1.area(len,wid)+pool1.road_size(len,wid))*prize_size;
    float prize_of_fence1=pool1.fence(len,wid)*prize_fence;
    cout<<"sun prize is:"<<prize_of_size1+prize_of_fence1<<endl;
    Swimming_Pool2 pool2; //创建圆形游泳池对象pool2
    cout<<"enter radius for circular swimming pool:"<<endl;
    float R;
    cin>>R;
    float prize_of_size2=(pool2.area(R)+pool2.road_size(R))*prize_size;
    float prize_of_fence2=pool2.fence(R)*prize_fence;
    cout<<"sun prize is:"<<prize_of_size2+prize_of_fence2<<endl;
    return 0;
}