#include<bits/stdc++.h>
using namespace std;
struct Matrix
{
    int row;
    int col;
};
int main()
{
    int n;
    cin>>n;
    map<char,Matrix> matrixMap;//记录每个矩阵的行列数
    for(int i=0;i<n;i++)
    {
        char name;
        int r,c;
        cin>>name>>r>>c;
        matrixMap[name]={r,c};
    }
    string expression;//输入表达式
    while(cin>>expression)
    {
        if(expression.size()==1)
        {
            continue;
        }
        stack<Matrix> Stack;//用于计算矩阵乘法的栈
        long long ans=0;
        bool error=false;
        for(int i=0;i<expression.size();i++)
        {
            char ch=expression[i];
            if(ch=='(')
            {
                continue;
            }
            else if(ch>='A'&&ch<='Z')
            {
                Stack.push(matrixMap[ch]);
            }
            else
            {
                if(Stack.size()<2)
                {
                    error=true;
                    break;
                }
                Matrix m2=Stack.top(); Stack.pop();
                Matrix m1=Stack.top(); Stack.pop();
                if(m1.col!=m2.row)
                {
                    error=true;
                    break;
                }
                Matrix res={m1.row,m2.col};
                Stack.push(res);
                ans+=(long long)m1.row*m1.col*m2.col;
            }
        }
        if(error)
        {
            cout<<"error"<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }
    }
}