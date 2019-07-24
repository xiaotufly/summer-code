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
}
void add(int x,int y)
{
	graph[x].push_back(y);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int ans=0;
		memset(vis,0,sizeof(vis));
		memset(match,0,sizeof(match));
		memset(m,0,sizeof(m));
		//memset(graph,0,sizeof(graph));
		
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			graph[i].clear(); 
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>m[i][j];
				if(m[i][j]==1)
				{
					add(i,j);
				//	add(j,i);
				}
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=0;j<graph[i].size();j++)
//			{
//				cout<<i<<" "<<graph[i][j]<<endl;
//			}
//		}
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i))
			{
				ans++;
				
			}//cout<<ans<<endl;
		}
	//	cout<<ans<<" "<<n<<endl;
		if(ans==n) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
