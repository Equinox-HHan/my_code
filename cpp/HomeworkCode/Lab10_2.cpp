#include<bits/stdc++.h>
using namespace std;
class Date
{
    public:
        Date(int yy,int mm,int dd)
        {
            year=yy;
            month=mm;
            day=dd;
        }
        Date operator+(int days) const
        {
            Date now=*this;
            now.day+=days;
            now.calculateDays();
            return now;
        }
        Date operator-(int days) const
        {
            return *this+(-days);
        }
        int operator-(const Date &other)
        {
            Date start = *this;
            Date end = other;
            int days = 0;

            if (start.year > end.year || 
                (start.year == end.year && start.month > end.month) ||
                (start.year == end.year && start.month == end.month && start.day > end.day)) 
                {
                    swap(start, end);
                }

            while (!(start.year == end.year && start.month == end.month && start.day == end.day)) 
            {
                start = start + 1;
                days++;
            }
        return days;
        }
        int getY()
        {
            return year;
        }
        int getM()
        {
            return month;
        }
        int getD()
        {
            return day;
        }
    private:
        int year;
        int month;
        int day;
        bool isYear(int y)
        {
            if(y!=100&&y%4==0)
            {
                return true;
            }
            else if(y%400==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int DayinMonth(int m,int y)
        {
            if(m==2)
            {
                if(isYear(y))
                {
                    return 29;
                }
                else
                {
                    return 28;
                }
            }
            else if(m==4||m==6||m==9||m==11)
            {
                return 30;
            }
            else 
            {
                return 31;
            }
        }
        void calculateDays()
        {
            while(day>DayinMonth(month,year))
            {
                day-=DayinMonth(month,year);
                month+=1;
                if(month>12)
                {
                    year+=1;
                    month=1;
                }
            }
            while(day<1)
            {
                month--;
                if (month < 1)
                {
                    month = 12;
                    year-=1;
                }
                day+=DayinMonth(year, month);
            }
        }
};

int main()
{
    Date date1(2025,12,16);
    Date date2=date1+17;
    Date date3(2026,3,3);
    cout<<date3.operator-(date1)<<endl;
    cout<<date2.getY()<<date2.getM()<<date2.getD()<<endl;
    return 0;
}
