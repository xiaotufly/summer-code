#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
const int size=32*32;
vector<int> graph[size];
int m,n,k;
int match[size];
int vis[size];
int f[size];
int mm[size][size];
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
				//nnnnnmcout<<y<<" "<<match[y]<<endl;
				return true;
			}
		}
		return false;
}
void init()
{
	int x=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)	
		{
			mm[i][j]=x;
			x++;
		}
	}	
} 
int main()
{
	while(cin>>m>>n>>k)
	{
		memset(vis,0,sizeof(vis));
		memset(match,0,sizeof(match));
		memset(graph,0,sizeof(graph));
		memset(f,0,sizeof(f));
		int ans=0;
		int ww=0;
		init();
		for(int i=1;i<=k;i++)
		{
			int x,y;
			cin>>x>>y;
			mm[y][x]=0;
		}
		//cout<<m<<" "<<n<<" "<<endl;
		if((m*n-k)%2==1) cout<<"NO"<<endl;
		else
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(mm[i][j]!=0)
					{
						//cout<<mm[i][j]<<endl;
						if((i+j)%2==1)
						{
							//
							if(i+1<=m&&mm[i+1][j]!=0)
							{
								add(mm[i][j],mm[i+1][j]);
							}
							if(i-1>=1&&mm[i-1][j]!=0)
							{
								add(mm[i][j],mm[i-1][j]);
								
							}
							if(j+1<=n&&mm[i][j+1]!=0)
							{
								add(mm[i][j],mm[i][j+1]);
									
							}
							if(j-1>=1&&mm[i][j-1]!=0)
							{
								add(mm[i][j],mm[i][j-1]);
							}
							ww++;
						}
					}
				}
			}
/*			for(int i=1;i<=m*n;i++){
				for(int j=0;j<graph[i].size();j++){
					cout<<i<<" "<<graph[i][j]<<endl;
				}
			}*/
			for(int i=1;i<=m*n;i++) 
			{
				memset(vis,0,sizeof(vis));
				if(dfs(i)) {
					ans++;
					//cout<<i<<" ";
				}
			}
			if(ans==(m*n-k)/2) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}		
	}
	return 0;
}
/*4 4 2
4 1
2 4
*/

