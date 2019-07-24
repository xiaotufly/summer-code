#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
const int size=505;
int n,m;
int deg[size];
int a[size];
int cnt=0;
vector <int> graph[size];
priority_queue<int> q;
void add(int x,int y)
{
	graph[x].push_back(y);
}
void topsort()
{
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0) q.push(-i);
	} 
	while(q.size())
	{
		int x=-q.top();
		q.pop();
		a[++cnt]=x;
		for(int i=0;i<graph[x].size();i++)
		{
			int y=graph[x][i];
			if(--deg[y]==0) q.push(-y);
		}
	}
//	int y;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(deg[j]==0)
//			{
//				y=j;
//				a[++cnt]=y;
//				deg[j]--;
//				break;
//			}
//		}
//		for(int j=0;j<n;j++)
//		{
//			if(graph[y][j]!=0) deg[graph[y][j]]--;
//			for(int i=1;i<=n;i++) cout<<deg[i]<<" ";cout<<endl;
//		}
//	}
}
int main()
{

	while(cin>>n>>m)
	{
		int x,y;
		for(int i=1;i<=m;i++)
		{
	
			cin>>x>>y;
			deg[y]++;
			add(x,y);
		}
		if(n==1) cout<<x<<endl;
		else
		{
			topsort();
			for(int i=1;i<=cnt;i++)
			{
				cout<<a[i];
				if(i!=n) cout<<" ";
			}
			cout<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			graph[i].clear();
		}
		cnt=0;
	}
	return 0;
}
