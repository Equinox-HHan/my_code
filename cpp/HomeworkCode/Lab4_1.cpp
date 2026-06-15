#include<bits/stdc++.h>
using namespace std;

class Point
{
    public:
    Point(float xx=0, float yy=0);//构造函数
    Point(Point&p);//复制构造函数

    void setPoint(float Px,float Py)//设置点坐标
    {
        x = Px;
        y = Py;
    }
    void showPoint(Point p)//显示点坐标
    {
        cout<<"persition is ";
        cout<<"("<<p.x<<","<<p.y<<")"<<endl;
    }
    void calculate_distance(Point p1,Point p2)//计算两点间距离
    {
        float num=sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
        cout<<num<<endl;
    }

    private:
    float x,y;

};

Point::Point(float xx,float yy)//构造函数实现
{
    x = xx;
    y = yy;
}
Point::Point(Point &p)//复制构造函数实现
{
    x = p.x;
    y = p.y;
}

int main()
{
    Point p1,p2;
    float x1,y1,x2,y2;
    cout<<"Enter the coordinates of point (x y): ";
    cin>>x1>>y1>>x2>>y2;
    p1.setPoint(x1,y1);
    p2.setPoint(x2,y2);
    p1.showPoint(p1);
    p2.showPoint(p2);
    cout<<"Distance between Point 1 and Point 2: ";
    p1.calculate_distance(p1,p2);

    return 0;
}
