#include<iostream>
#include<cmath>
using namespace std;

class Point
{
    public:
    Point(int xx=0,int yy=0)//构造函数
    {
        x = xx;
        y = yy;
        cout<<"point构造函数被调用"<<endl;
    }
    Point(Point&p)//复制构造函数
    {
        x = p.x;
        y = p.y;
    }

    void setPoint(int px,int py)//输入形参改变点（0，0）的坐标
    {
        x = px;
        y = py;
    }
    int getX()//需要使用成员函数访问接下来的private内容
    {
        return x;
    }
    int getY()
    {
        return y;
    }   

    ~Point() 
    {
        cout<<"point析构函数被调用"<<endl;
    }
    
    private:
    int x,y;
};
class Rect
{
    public:
    Rect(Point p1,Point p2 );//构造函数声明
    Rect(Rect&R);//复制构造函数

    int Area()//计算面积和周长
    {
       return abs((point1.getX()-point2.getX())*(point1.getY()-point2.getY()));
    }
    int Round()
    {
       return 2*(abs(point1.getX()-point2.getX())+abs(point1.getY()-point2.getY()));
    }

    private:
    Point point1,point2;//数据成员是Point类的对象，内嵌对象
};
Rect::Rect(Point p1,Point p2):point1(p1),point2(p2)//初始化列表，输入的形参为point类p1和p2，将其赋值给数据成员point1和point2
{
    cout<<"rect构造函数被调用"<<endl;
}
Rect::Rect(Rect&R):point1(R.point1),point2(R.point2)//复制构造函数的实现
{
    cout<<"rect复制构造函数被调用"<<endl;
}

int main()
{
    cout << unitbuf;
    cout<<"test"<<endl;
    Point xp1,xp2;//创建两个point类对象
    cout<<"please enter four number to set two points (x,y):"<<endl;
    int x1,x2,y1,y2;//四个坐标点
    cin>>x1>>y1>>x2>>y2;
    xp1.setPoint(x1,y1);//对象.成员函数（形参），将(0,0)改为输入的坐标
    xp2.setPoint(x2,y2);
    Rect r1(xp1,xp2);//创建一个rect类对象r1，传入两个point类对象作为形参
    cout<<"Area="<<r1.Area()<<endl;
    Rect r2(r1);
    cout<<"Round="<<r2.Round()<<endl;
    system("pause");
    return 0;
}