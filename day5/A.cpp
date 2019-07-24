#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
const int size=6005;
int dp[size][10];//动态dp 
int qwq[size];//气氛值 
int vis[size];//是否有上司 
int n;
vector <int> graph[size];
void add(int x,int y)
{
	vis[x]=1;
	graph[y].push_back(x);
}
void ww(int ff)
{
	dp[ff][0]=0;
	dp[ff][1]=qwq[ff];
	for(int i=0;i<graph[ff].size();i++)
	{	
		int y=graph[ff][i];
		ww(y);
		dp[ff][0]+=max(dp[y][0],dp[y][1]);
		dp[ff][1]+=dp[y][0];
		//cout<<dp[ff][0]<<" "<<dp[ff][1]<<endl;
	}
}
int main()
{
	while(cin>>n)
	{
		
		memset(vis,0,sizeof(vis));
		memset(qwq,0,sizeof(qwq));
		memset(dp,0,sizeof(dp));
		memset(graph,0,sizeof(graph));
		for(int i=1;i<=n;i++)
		{
			cin>>qwq[i];
		}
		for(int i=1;i<=n;i++)
		{
			int k,l;
			cin>>k>>l;
			if(k==0&&l==0) break;
			add(k,l);//存关系 
		}
		int ff;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]!=1) 
			{
				ff=i;
				break;
			}
		}
		ww(ff);
		cout<<max(dp[ff][0],dp[ff][1])<<endl;
	//	graph.clear();
	}
	return 0;
}
