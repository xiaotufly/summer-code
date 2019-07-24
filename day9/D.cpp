//#include<iostream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//int a[1005][10005],d[1005],dd[1005],mn[1005];
//bool v[10005];
//int n,m,x0;
//void dijkstra(int ii)
//{
//	memset(d,0x3f,sizeof(d));
//	memset(v,0,sizeof(v));
//	d[ii]=0;
//	for(int i=1;i<=n;i++)
//	{
//		int x=0;
//		for(int j=1;j<=n;j++)
//			if(!v[j]&&(x==0||d[j]<d[x])) x=j;
//		v[x]=1;
//		for(int y=1;y<=n;y++)
//			d[y]=min(d[y],d[x]+a[x][y]); 
//	}
//}
//int main()
//{
//	cin>>n>>m>>x0;
//	memset(a,0x3f,sizeof(a));
//	for(int i=1;i<=n;i++)
//	{
//		a[i][i]=0;
//	}
//	for(int i=1;i<=m;i++)
//	{
//		int x,y,z;
//		cin>>x>>y>>z;
//		a[x][y]=min(a[x][y],z);
//		//a[y][x]=a[x][y];
//	}
//	dijkstra(x0);
//	for(int i=1;i<=n;i++) dd[i]=d[i];
//	for(int i=1;i<=n;i++)
//	{
//		dijkstra(i);
//		mn[i]=dd[i]+d[x0];
//		cout<<mn[i]<<" "<<dd[i]<<" "<<d[x0]<<endl;
//	}
//	sort(mn,mn+n+1);
//	cout<<mn[n];
//	return 0;
//} 
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1010,M=100010;
int head[N],ver[M],edge[M],Next[M],d[N],dd[N],mn[N];
int n,m,tot,x0;
queue<int> q;
bool v[N];
void add(int x,int y,int z)
{
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
void spfa(int ii)
{
	//while (!q.empty()) q.pop();
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[ii]=0;
	v[ii]=1;
	q.push(ii);
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
	cin>>n>>m>>x0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		//add(y,x,z);
	}
	spfa(x0);
	for(int i=1;i<=n;i++) dd[i]=d[i];
	for(int i=1;i<=n;i++)
	{
		spfa(i);
		mn[i]=dd[i]+d[x0];
		//cout<<mn[i]<<" "<<dd[i]<<" "<<d[x0]<<endl;
	}
	sort(mn,mn+n+1);
	cout<<mn[n]<<endl;
	return 0;
}

