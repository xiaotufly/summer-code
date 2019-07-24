#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
const int size=2000;
int m[size][size];
int match[size];
int vis[size];
vector<int> graph[size];
int u[size];//是否在校学生 
int v[size];//是否回家
int f[size];//需要睡觉的人 
int n,ans,sum;
bool dfs(int x)
{
	int y;
	for(int i=0;i<graph[x].size();i++)
		if(!vis[y=graph[x][i]])
		{
			vis[y]=1;
			if(!match[y]||dfs(match[y]))
			{
				match[y]=x;
				return true;				
			}
		}
	return false;
}//二分匹配 

void add(int x,int y)
{
	graph[x].push_back(y);
}//存边 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(match,0,sizeof(match));
		memset(graph,0,sizeof(graph));
		memset(vis,0,sizeof(vis));
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		ans=0;
		sum=0;
		//初始化 
		cin>>n;
		for(int i=1;i<=n;i++) cin>>u[i];//是否在校 
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];//是否回家 
			if(u[i])//如果是在校生 
			{
				if(!v[i])//如果不回家 
				{
					f[i]=1;//要睡觉标记 
					sum++;//要睡觉的人增加 
				}
			}
			if(!u[i])//如果不是在校生 
			{
				 f[i]=1;//要睡觉标记
				 sum++;//要睡觉的人增加 
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(u[i]&&f[i]) add(i,i);
		} 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>m[i][j];
				if(m[i][j]&&f[i]&&u[j])
				{
					add(i,j);
					//cout<<i<<" "<<j<<endl;
					//cout<<i<<" "<<j<<endl;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		if(ans==sum) cout<<"^_^"<<endl;
		else cout<<"T_T"<<endl;
	}
	return 0;
}

