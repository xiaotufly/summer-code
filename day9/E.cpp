#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int d[3100][3100];
struct node
{
	int x,y;
}s[300];
int a[300];
int ww,mon,n;
int main()
{
	while(cin>>n>>ww)
	{
		memset(d,0x3f,sizeof(d));
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		for(int i=2;i<=n-1;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].x>>s[i].y;
		}
		for(int i=1;i<=n;i++) d[i][i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int zz;
				if(i!=j) 
				{
					int z=(abs(s[i].x-s[j].x)+abs(s[i].y-s[j].y))*ww-a[i];
					d[i][j]=z;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
		cout<<d[1][n]<<endl;
	}
	return 0;
}

