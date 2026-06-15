#include<bits/stdc++.h>

class Point
{
public:
    // 构造函数实现
    Point(int xx, int yy);
    
    // 复制构造函数实现
    Point(const Point& p); 
    
    int getx() { return x; }
    int gety() { return y; }
    
    double Distance(Point a,Point b)
    {
        double dx = a.getx()-b.getx();
        double dy = a.gety()-b.gety();
        return sqrt(dx * dx + dy * dy);
    }
    
    double calculateS(Point a,Point b,Point c)
    {
        double ab = Distance(a, b);
        double bc = Distance(b, c);
        double ca = Distance(c, a);
        double s = (ab + bc + ca) / 2.0;  // 半周长
        
        return sqrt(s * (s - ab) * (s - bc) * (s - ca));
    }
    
    // 析构函数
    ~Point() = default;
    
private:
    int x;
    int y;
};
