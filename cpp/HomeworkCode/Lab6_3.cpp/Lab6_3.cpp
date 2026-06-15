#include"Point.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	Point a(1,1);
	Point b(10,17);
	Point c(20,21);
	cout<<a.Distance(a,c)<<endl;
	cout<<a.calculateS(b,c,a)<<endl;
	return 0; 
}
