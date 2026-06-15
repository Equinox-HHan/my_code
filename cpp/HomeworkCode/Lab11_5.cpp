#include<bits/stdc++.h>
using namespace std;
int m,n;
int arr[21];
vector<int> summary;
bool visited[21];
void dfs(int num,int position,int sum)
{
    if(num==n)
    {
        auto pos=find(summary.begin(),summary.end(),sum);
        if(pos==summary.end())
        {
            summary.push_back(sum);
        }
        return;
    }
    for(int i=position;i<m;i++)
    {
        if(visited[i]==false)
        {
            visited[i]=true;
            dfs(num+1,i+1,sum+arr[i]);
            visited[i]=false;
        }        
    }
}
int main()
{
    memset(visited,false,sizeof(visited));
    cin>>m>>n;
    int counter=0;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    dfs(0,0,0);
    cout<<summary.size()<<endl;
    return 0;
}