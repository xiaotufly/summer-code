#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
const int N=1010,M=100010;
int head[N],ver[M],edge[M],Next[M],d[N],dd[N],mn[N],dd[N];
int n,m,tot,k,ans;
queue<int> q;
vector<int> graph[M];
bool v[N];
void add(int x,int y,int z)
{
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
void spfa()
{
	//while (!q.empty()) q.pop();
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[1]=0;
	v[1]=1;
	q.push(1);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		v[x]=0;
		for(int i=head[x];i;i=Next[i])
		{
			int y=ver[i];
			int z=edge[i];
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				if((!v[y])) q.push(y),v[y]=1;
			}
		}
	}
}
int main()
{ 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	spfa();
	for(int i=1;i<=n;i++) dd[i]=d[i];
	for(int i=1;i<=n;i++)
	{
		
	}
	return 0;
}
