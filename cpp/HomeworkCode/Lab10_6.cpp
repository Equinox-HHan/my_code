#include<bits/stdc++.h>
using namespace std;

bool visited[10][10];
long long max_arr[10][10];
long long min_arr[10][10];
vector<long long> number;
vector<char> opr;

pair<long long,long long> calculate(int l,int r)
{
    if(l==r)
    {
        return{number[l],number[l]};
    }
    if(visited[l][r])
    {
        return{max_arr[l][r],min_arr[l][r]};
    }

    // 修正：max_value 应该初始化为 LLONG_MIN
    long long max_value=LLONG_MIN;  // 改为 LLONG_MIN
    long long min_value=LLONG_MAX;

    for(int k=l;k<r;k++)
    {
        auto left=calculate(l,k);
        auto right=calculate(k+1,r);
        char op=opr[k];

        vector<long long> values;
        if(op=='+')
        {
            values=
            {   
                left.first+right.first,
                left.first+right.second,
                left.second+right.first,
                left.second+right.second,
            };
        }
        else if(op=='*')  // 最好明确说明是乘法
        {
            values=
            {
                left.first*right.first,
                left.first*right.second,
                left.second*right.first,
                left.second*right.second,
            };
        }
        // 可以添加其他操作符支持
        
        for(long long val:values)
        {
            if(val>max_value)
            {
                max_value=val;
            }
            // 修正：去掉分号，正确比较
            if(val<min_value)  // 注意：应该是 min_value，不是 max_value！
            {
                min_value=val;
            }
        }
    }
    visited[l][r]=true;
    max_arr[l][r]=max_value;
    min_arr[l][r]=min_value;

    return{max_value,min_value};
}

int main()
{
    string line;
    getline(cin, line);
    
    stringstream ss(line);
    long long num;
    char op;
    
    ss >> num;
    number.push_back(num);
    
    while (ss >> op >> num) {
        opr.push_back(op);
        number.push_back(num);
    }
    
    memset(visited, 0, sizeof(visited));
    
    auto result = calculate(0, number.size() - 1);
    cout << result.first << endl;
    cout << result.second << endl;
    
    return 0;
}