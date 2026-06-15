#include"Point.h"
#include<bits/stdc++.h>
using namespace std;

Point::Point(int xx,int yy)
{
	x=xx;
	y=yy;	
}
Point::Point(const Point&p)
{
	x=p.x;
	y=p.y;
}

