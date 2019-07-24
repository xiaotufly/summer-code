#include<iostream>
#include<cstring>
using namespace std;
int d[3100][3100],n,m;
int main()
{
	cin>>n>>m;
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		d[x][y]=min(d[x][y],z);
		d[y][x]=d[x][y];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
