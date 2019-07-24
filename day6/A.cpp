#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int size=2005; 
vector<int> graph[size];
int k,m,n,ans;
int vis[size];
int match[size];
void add(int x,int y)
{
	graph[x].push_back(y);	
} 
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
				//cout<<x<<" "<<y<<endl;
				return true;
			}
		}
		return false;
}
int main()
{
	while(cin>>k)
	{
		if(k==0) break;
		cin>>m>>n;
		memset(match,0,sizeof(match));
		memset(graph,0,sizeof(graph));
//		for(int i=0;i<=2000;i++)
//		{
//			graph[i].clear();
//		}
		ans=0;int x,y;
		for(int i=1;i<=k;i++)
		{
			
			cin>>x>>y;
			add(x,y+m);
		}
		for(int i=1;i<=m;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
