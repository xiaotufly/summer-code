#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eqs=1e-9;
int g[20][20];
int dp[200000][20],dis[20];
int t;
int n,m;
int w,l,r,minl;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		memset(g,INF,sizeof(g));
		while(m--)
		{
			cin>>l>>r>>w;
			l--;r--;
			if(g[l][r]>w) g[l][r]=g[r][l]=w;
		}
		for(int i=0;i<n;i++) g[i][i]=0;
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		
		memset(dp,INF,sizeof(dp));
		memset(dis,INF,sizeof(dis));
		dp[1][0]=0;
		dis[0]=0;
		m=1<<n;
		for(int i=1;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dp[i][j]==INF) continue;
				for(int k=0;k<n;k++)
				{
					if(i&(1<<k)||g[j][k]==INF) continue;
					if(dp[i|(1<<k)][k]>dp[i][j]+g[j][k])
					{
						dp[i|(1<<k)][k]=dp[i][j]+g[j][k];
						dis[k]=min(dis[k],dp[i|(1<<k)][k]);
					}
				}
			}
		}
		minl=INF;
		for(int i=0;i<n;i++)
		{
			minl=min(minl,dp[m-1][i]+dis[i]);
		}
		cout<<minl<<endl;
	}
	return 0;
}
