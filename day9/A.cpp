#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int a[1005][10005],d[1005];
bool v[10005];
int n,m,s,t;
void dijkstra()
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[s]=0;
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=1;j<=n;j++)
			if(!v[j]&&(x==0||d[j]<d[x])) x=j;
		v[x]=1;
		for(int y=1;y<=n;y++)
			d[y]=min(d[y],d[x]+a[x][y]); 
	}
}
int main()
{
	cin>>n>>m>>s>>t;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=min(a[x][y],z);
		a[y][x]=a[x][y];
	}
	dijkstra();
	cout<<d[t]<<endl;
	return 0;
} 
