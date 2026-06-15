#include<bits/stdc++.h>
using namespace std;
string source,target;
vector<char> my_path;
vector<char> Stack;
void solve(int source_index,int target_index)
{
    if(target_index==target.size())
    {
        for(int i=0;i<my_path.size();i++)
        {
            cout<<my_path[i]<<(i==my_path.size()-1?"":" ");
        }
        cout<<endl;
    }
    if(source_index<source.size())
    {
        my_path.push_back('i');
        Stack.push_back(source[source_index]);
        solve(source_index+1,target_index);
        my_path.pop_back();
        Stack.pop_back();
    }
    if(!Stack.empty()&&Stack.back()==target[target_index])
    {
        my_path.push_back('o');
        char temp=Stack.back();
        Stack.pop_back();
        solve(source_index,target_index+1);
        my_path.pop_back();
        Stack.push_back(temp);
    }
}
int main()
{
    while(cin>>source>>target)
    {
        cout<<"["<<endl;
        if(source.size()==target.size())
        {
            string s1=source;
            string s2=target;
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if(s1==s2)
            {
                solve(0,0);
            }
        }
        cout<<"]"<<endl;
    }
    return 0;
}