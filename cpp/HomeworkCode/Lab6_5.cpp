#include<bits/stdc++.h>
using namespace std;

const int maxN=1000;
int N;
int arr[maxN][maxN];
bool visited[maxN][maxN];

int dfs(int x,int y,int color)
{
	if(x<0||x>=N||y<0||y>=N||visited[x][y]=false||arr[x][y]!=color)
	{
		return 0;
	}
	int size=1;
	visited[x][y]=true;
	for(int dx=-1;dx<2;dx++)
	{
		for(int dy=-1;dy<2;dy++)
		{
			size+=dfs(x+dx,y+dy,color);
		}
	}
	return size;
}

int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>arr[i][j];
			visited[i][j]=false;
		}
	}
	int maxSize=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			int color=arr[i][j];
			int area=dfs(i,j,color);
			if(area>maxSize)
			{
				maxSize=area;
			}
		}
	}
	cout<<maxSize;
	return 0;
}


