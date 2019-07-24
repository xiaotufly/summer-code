#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int s1[1000],s2[1000];
int dp[1000][1000];
int t,n,m;
int main()
{
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>s1[i];
		cin>>m;
		for(int i=1;i<=m;i++) cin>>s2[i];
		for(int i=1;i<=n;i++)
		{
			int val=0;
			if(s2[0]<s1[i]) val=dp[i-1][0];
			for(int j=1;j<=m;j++)
			{
				if(s1[i]==s2[j]) dp[i][j]=val+1;
				else dp[i][j]=dp[i-1][j];
				if(s2[j]<s1[i]) val=max(val,dp[i-1][j]);
			}
		}
		int sum=0;
		for (int i = 1; i <= m; ++i)
    	{
        	sum = max (dp[n][i],sum);
    	}
		cout<<sum<<endl;
		if(t!=0) cout<<endl;
	}
	return 0;
}
