#include<bits/stdc++.h>
using namespace std;
int A[432-123+1]={0};
bool isComposedbyParticularNumber(int number)
{
    string s=to_string(number);
    char a=s[1];char b=s[2];char c=s[3];
    if(a=='6'||a=='7'||a=='8'||a=='9'||b=='6'||b=='7'||b=='8'||b=='9'||c=='6'||c=='7'||c=='8'||c=='9')
        {
            return false;
        }
    return true;
}

bool isNoFive(int number)
{
    if(number%5==0)
    {
        return false;
    }
    return true;
}

void produceNumber()
{
    int i=123;int j=0;
    for(i;i<=432;i++)
    {
        if(isNoFive(i)&&isComposedbyParticularNumber(i))
        {
            if(i%111!=0)
            {
                A[j]=i;
                cout<<A[j]<<endl;
                j+=1;
            }
        }
    }
    return;
}

int main()
{
    produceNumber();
    return 0;
}