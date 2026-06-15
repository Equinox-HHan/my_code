#include<bits/stdc++.h>
using namespace std;

class Exam
{
	public:
		Exam(int number)
		{
			ID=number;
			counter++;
			cout<<"ID: "<<ID<<" created;";
			cout<<"Now have "<<counter<<" object;"<<endl;
		}
		void showID()
		{
			cout<<ID<<endl;
		}
		~Exam()
		{
			counter--;
			cout<<"ID: "<<ID<<" destroyed;";
			cout<<"Now have "<<counter<<" object;"<<endl;
		}
		static int showCounter()
		{
			return counter;
		}
	private:
		int ID;
		static int counter;
};
int Exam::counter=0;
int test()
{
	Exam A1(19870624);
	Exam A2(20061102);
	A1.showID(); 
	A2.showID();
	cout<<Exam::showCounter()<<endl;
}
int main()
{
	Exam A3(20070411);
	Exam A4(20060914);
	cout<<Exam::showCounter()<<endl;
	test();
	cout<<Exam::showCounter()<<endl;
	return 0;
}

