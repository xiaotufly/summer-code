#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=100010,M=1000010;
int head[N],ver[M],edge[M],Next[M],d[N];
int n,m,tot,s,t;
queue<int> q;
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
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[s]=0;
	v[1]=1;
	q.push(s);
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
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	spfa();
	cout<<d[t]<<endl;
	return 0;
}
