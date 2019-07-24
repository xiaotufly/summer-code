#include<iostream>
#include<queue>
#include<string>
#include<cmath>
#include<cstring>
#include<bits/stdc++.h>
//#include<vector>
using namespace std;
const int size=100005;
int f[size][20],d[size],dist[size];
int vis[size*2];
//vector<int>graph[size];
int ver[2*size];
int nex[2*size],head[size];
//string name[size*2];//用于字符串和下标之间的转化，存储目录名 
//edge[2*size]
int n,m,tot,tt,qwq;
queue<int > q;
map<string,int>mp;
int id=0;
void add(int x,int y)//int z
{
	ver[++tot]=y;
	//edge[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
} 
void bfs()//预处理 
{
	
	for(int i=1;i<=id;i++)
	{
		if(vis[i]==0) 
		{
//			cout<<"   "<<i<<endl;
			q.push(i);
			d[i]=1;
			break;
		}
		
	}
	
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nex[i])
		{
			int y=ver[i];
			if(d[y]) continue;
			d[y]=d[x]+1;
			//dist[y]=dist[x]+edge[i];
			f[y][0]=x;
			for(int j=1;j<=tt;j++)
				f[y][j]=f[f[y][j-1]][j-1];
			q.push(y);
		}
	}
}
int lca(int x,int y)//lca lca 
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
//		return x;
}
//int findname(string s)//字符串数组的find函数，因为之前用find炸了就自己弄了个 
//{
//	for(int i=1;i<=qwq;i++)
//	{
//		if(name[i]==s) return i;
//	}
//	return -1;	
//}
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		mp.clear();
		cin>>n>>m;
		id=0;
		tt=(int)(log(n)/log(2))+1;
		for(int i=1;i<=n;i++) head[i]=d[i]=0,vis[i]=0;
		tot=0;
		qwq=0;
		for(int i=1;i<n;i++)
		{
			string s1;
			string s2;
			cin>>s1>>s2;
			
			if(mp[s1]==0)mp[s1]=++id;
			if(mp[s2]==0)mp[s2]=++id;
			vis[mp[s1]]=1;
//			int qaq1,qaq2;
//			if(findname(s1)!=-1)
//			{
//				qaq1=findname(s1);
//			}
//			else
//			{
//				name[++qwq]=s1;
//				qaq1=qwq;
//			}
//			if(findname(s2)!=-1)
//			{
//				qaq2=findname(s2);
//			}
//			else
//			{
//				name[++qwq]=s2;
//				qaq2=qwq;
//			}		
			add(mp[s1],mp[s2]);
			add(mp[s2],mp[s1]);
		}
		bfs();
		string xx,yy;
		int c;
		for(int i=1;i<=m;i++)
		{
			cin>>xx>>yy;
			int qq=lca(mp[xx],mp[yy]);
			int qx=mp[xx];
			int qy=mp[yy];
			int ff=d[qq];
			int fx=d[qx];
			int fy=d[qy];
//			cout<<qq<<" "<<qx<<" "<<qy<<endl;
			if(qq==qy) c=0;
			else c=1;
			//if()
			//ww[i]=dist[xx[i]]+dist[yy[i]]-2*dist[lca(xx[i],yy[i])];
			//cout<<ww[i]<<endl;
			int sum=fx-ff+c;
			//cout<<d[lca(findname(xx),findname(yy))-1]<<" "<<d[findname(xx)]<<" "<<d[findname(yy)]<<endl;
			cout<<sum<<endl;
		}
		
	}
	return 0;
}
