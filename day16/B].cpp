#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll n;
int a[25];
ll dp[25][5][20];
ll dfs(ll pos,ll mod,ll limit,ll f)
{
	if(pos==0)return mod==0&&f==2;
	if(!limit&&dp[pos][f][mod]!=-1) return dp[pos][f][mod];
	int up=limit?a[pos]:9;
	ll ans=0;
	int _mod,_f;
	for(int i=0;i<=up;i++)
	{
		_mod=(mod*10+i)%13;
		_f=f;
		if(f==0&&i==1) _f=1;
		if(f==1&&i!=1) _f=0;   
		if(f==1&&i==3) _f=2;
		
		ans+=dfs(pos-1,_mod,limit&&i==up,_f);
	}
	if(!limit) dp[pos][f][mod]=ans;
	return ans; 
}
ll solve(ll x)
{
	memset(dp,-1,sizeof(dp));
	ll top=0;
	while(x)
	{
		a[++top]=x%10;
		x/=10;
	}
	return dfs(top,0,1,0);
}
int main()
{
	while((scanf("%lld",&n))!=EOF)
	{
		cout<<solve(n)<<endl;
	}
	return 0;
} 
