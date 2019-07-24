#include<iostream>                                                                                                      
#include<vector>
#include<string>
#include<cstring>
using namespace std;
const int size=1e5+5;
int n;
int u[size];
int v[size];
int dp[size][10];
int vis[size];
int f[size][10];
int sum;
int id;
vector<int> graph[size];
//void add(int x,int y)
//{
//	graph[x].push_back(y);
//}
void ww(int i)
{
//cout<<i<<endl;
//	add(u[i],v[i]);
//	add(v[i],u[i]);
	if(i==0) return ; 
	if(vis[u[i]]!=1&&vis[v[i]]!=1)
	{
		sum++;
		vis[u[i]]=1;
		vis[v[i]]=1;
	}
	else
	{
		ww(i-1);
	}
	cout<<sum<<endl;
}
//void ww(int x)
//{
//	f[x][0]=0;
//	f[x][1]=vis[x];
//	for(int i=0;i<graph[x].size();i++)
//	{
//		int y=graph[x][i];
//		ww(y);
//		f[x][0]+=max(f[y][0],f[y][1]);
//		f[x][1]+=f[y][0];
//	}
//}
int main()
{
	cin>>n;
	//init();
	id=0x3f;
	for(int i=1;i<n;i++)	
	{
		int x,y;
		cin>>x>>y;
		u[i]=x;
		v[i]=y;
	}
	if(n%2!=0) cout<<-1<<endl;
	else
	{
		for(int i=n-1;i>=1;i--)
		{
			int f=0;
			ww(i);
			for(int j=1;j<n;j++)
			{
				if(vis[j]!=1)
				{
					f=1;
					break;
				}
			}
			if(f!=1&&sum!=0)
			{
				id=min(id,sum);
			}
			sum=0;
		}
		cout<<n-1-id<<endl;
	}
	return 0;
}
