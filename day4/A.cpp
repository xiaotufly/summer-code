#include<iostream>
#include<queue>
#include<string>
#include<cmath>
//#include<vector>
using namespace std;
const int size=70005;
int f[size][20],d[size],dist[size];
//vector<int>graph[size];
int  ver[2*size],nex[2*size],edge[2*size],head[size];
int n,m,tot,tt;
queue<int > q;
void add(int x,int y,int z)
{
	ver[++tot]=y;
	edge[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
} 
void bfs()
{
	q.push(1);
	d[1]=1;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nex[i])
		{
			int y=ver[i];
			if(d[y]) continue;
			d[y]=d[x]+1;
			dist[y]=dist[x]+edge[i];
			f[y][0]=x;
			for(int j=1;j<=tt;j++)
				f[y][j]=f[f[y][j-1]][j-1];
			q.push(y);
		}
	}
}
int lca(int x,int y)
{
	if(d[x]>d[y]) swap(x,y);
	for(int i=tt;i>=0;i--)
	{
		if(d[f[y][i]]>=d[x]) y=f[y][i];
	}
		if(x==y) return x;
		for(int i=tt;i>=0;i--)
			if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
		return f[x][0];
	
}
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		tt=(int)(log(n)/log(2))+1;
		for(int i=1;i<=n;i++) heaad[i]=d[i]=0;
		tot=0;
		for(int i=1;i<n;i++)
		{
			int x;int y;int z;
			cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,z);
		}
		bfs();
		int xx[2*size],yy[2*size],ww[2*size];
		for(int i=1;i<=m;i++)
		{
			cin>>xx[i]>>yy[i];
			ww[i]=dist[xx[i]]+dist[yy[i]]-2*dist[lca(xx[i],yy[i])];
			cout<<ww[i]<<endl;
		}
	}
	return 0;
} 
