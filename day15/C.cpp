#include<iostream>
#include<cstring>
using namespace std;
const int size=1000;
int t,a[size],n,dp[size][size],b[size];
int main()
{
	cin>>t;
	int h=1;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				dp[i][j]=0x3f3f3f3f;
			}
		}
		//cout << dp[1][1] << endl;
		for(int len=1;len<=n;len++)//长度 
		{ 
			for(int l=1;l<=n-len+1;l++)//左边 
			{
				int r=len+l-1;//右边 
				for(int k=l;k<=r;k++)//决策 
				{
					dp[l][r]=min(dp[l][r],dp[l][k-1]+a[k]+dp[k+1][r]+b[l-1]+b[r+1]);
				}
			}
		}
		cout<<"Case #"<<h<<": "<<dp[1][n]<<endl;
		h++;
	}
	return 0;
}
