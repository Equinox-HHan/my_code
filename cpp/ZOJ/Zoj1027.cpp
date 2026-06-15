#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        void solve()
        {
            cin>>testTime;
            for(int i=0;i<testTime;i++)
            {
                getData();
                DPfunc();
                cout<<answer<<endl;
            }
        }
    private:
        vector<vector<int>> dp;
        string str1,str2;
        int answer=0;
        int len1,len2;
        int testTime;
        void getData()
        {
            cin>>len1>>str1;
            cin>>len2>>str2;
        }
        int getPoint(char a,char b)
        {
            auto func=[](char c)
            {
                if(c=='A')
                {
                    return 0;
                }
                if(c=='C')
                {
                    return 1;
                }
                if(c=='G')
                {
                    return 2;
                }
                if(c=='T')
                {
                    return 3;
                }
                return 4;
            };
            int point[5][5]=
            {
                {5,-1,-2,-1,-3},
                {-1,5,-3,-2,-4},
                {-2,-3,5,-2,-2},
                {-1,-2,-2,5,-1},
                {-3,-4,-2,-1,0}
            };
            return point[func(a)][func(b)];
        }
        void DPfunc()
        {
            //处理数据＋初始化
            str1=" "+str1;
            str2=" "+str2;
            dp.assign(len1+1,(vector<int>(len2+1,-100000)));
            dp[0][0]=0;//最基础的递推起点
            for(int i=1;i<=len1;i++)
            {
                dp[i][0]=dp[i-1][0]+getPoint(str1[i],'-');
            }
            for(int j=1;j<=len2;j++)
            {
                dp[0][j]=dp[0][j-1]+getPoint('-',str2[j]);
            }
            for(int i=1;i<=len1;i++)
            {
                for(int j=1;j<=len2;j++)
                {
                    int choiceA=dp[i-1][j-1]+getPoint(str1[i],str2[j]);
                    int choiceB=dp[i][j-1]+getPoint('-',str2[j]);
                    int choiceC=dp[i-1][j]+getPoint(str1[i],'-');
                    dp[i][j]=max({choiceA,choiceB,choiceC});
                }
            }
            answer=dp[len1][len2];
        }
};