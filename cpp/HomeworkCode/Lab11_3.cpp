#include<bits/stdc++.h>
using namespace std;
struct Student
{
    string Name;
    string ID;
    string Gender;
};
struct  Book
{
    string bookName;
    string Author;
    double Price;
};
template<class T>
class Store
{
    public:
        Store();
        T &getInfo();
        void setInfo(const T &p);
        ~Store();
    private:
        T Info;
};
template<class T>
T &Store<T>::getInfo()
{
    return Info;
}
template<class T>
void Store<T>::setInfo(const T &p)
{
    Info=p;
}

int main()
{
    Student student={"zengjuhan","20254001064","male"};
    Store<Student> s1;
    s1.setInfo(student);
    cout<<"#Student:"<<s1.getInfo().Name<<"-----"<<s1.getInfo().ID<<endl;

    Book book={"Harry Potter","J.K",999.999};
    Store<Book> s2;
    s2.setInfo(book);
    cout<<"#Infomation"<<s2.getInfo().bookName<<"-----"<<
    s2.getInfo().Author<<"-----"<<s2.getInfo().Price<<endl;
    return 0;
}