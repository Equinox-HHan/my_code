#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	int arr[N][M];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin>>arr[i][j];		
		}
	}
	
	double average[M];
	int maxPoint[M];
	memset(average,0,sizeof(average));
	memset(maxPoint,0,sizeof(maxPoint));
	
	for(int j=0;j<M;j++)
	{
		for(int i=0;i<N;i++)
		{
			average[j]+=arr[i][j];
			if(arr[i][j]>maxPoint[j])
			{
				maxPoint[j]=arr[i][j];
			}
		}
	}
	
	for(int i=0;i<M;i++)
	{
		average[i]=average[i]*1.0/N;
		cout<<"#--Average "<<i+1<<" : "<<average[i]<<endl;
		cout<<"#--MaxPoint "<<i+1<<" : "<<maxPoint[i]<<endl;
	}
	return 0;
}
