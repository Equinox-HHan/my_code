#include<bits/stdc++.h>
using namespace std;
int specialYear(int yy,int y)
{   
    int addDay=0;
    for(int i=yy;i<=y;i++)
    {
        if(i%4==0&&i%100!=0)
        {
            addDay+=1;
        }
    }
    return addDay;
}

bool isspecialYear(int yy,int y)
{
    for(int j=yy;j<=y;j++)
    {
        if(j%4==0&&j%100!=0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
}

int caculateDays(int yy,int mm,int dd,int y,int m,int d)
{   
    int days;
    if(m==mm)
    {
        if(d>=dd)
        {
            days=(y-yy)*365+(d-dd);
            days=days+specialYear(yy,y);
        }
        else
        {
            days=(y-yy)*365-(d-dd);
            days=days+specialYear(yy,y);
        }
        return days;
    }
    else if(m>mm)
    {
        if(m-mm==1)
        {
            if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
            {
                days=(y-yy)*365+(31-dd)+d;
                days=days+specialYear(yy,y);
            }
            else if(mm==2)
            {
                if(isspecialYear)
                {
                    days=(y-yy)*365+(29-dd)+d;
                    days=days+specialYear(yy,y);
                }
                else
                {
                    days=(y-yy)*365+(28-yy)+d;
                    days=days+specialYear(yy,y);
                }
            }
            else
            {
                days=(y-yy)*365+(30-dd)+d;
                days=days+specialYear(yy,y);
            }
        }
        else
        {
            if(d>=dd)
            {   
                days=(y-yy)*365+(m-mm)*30+(d-dd);
                days=days+specialYear(yy,y);
                
            }
            else
            {
                days=(y-yy)*365+(m-mm)*30-(dd-d);
                days=days+specialYear(yy,y);
            }
        }
        return days;
    }
    else
    {
        if(mm-m==1)
        {
            if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
            {
                days=(y-yy)*365-((31-d)+dd);
                days=days+specialYear(yy,y);
            }
            else if(m==2)
            {
                if(isspecialYear)
                {
                    days=(y-yy)*365-((29-d)+dd);
                    days=days+specialYear(yy,y);
                }
            }
            else
            {
                days=(y-yy)*365-((30-d)+dd);
                days=days+specialYear(yy,y);
            }
        
        }
    }
    return days;

}

int main()
{
    cout<<"enter the birth and the date now"<<endl;
    int yy,mm,dd,y,m,d;
    cin>>yy>>mm>>dd>>y>>m>>d;
    cout<<caculateDays(yy,mm,dd,y,m,d)<<endl;
    return 0;
}