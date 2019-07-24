#include<iostream>
#include<cstring>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
//优化cin，cout。但是速度还是没有c的快 啊！ 
int n,m;
const int size=100005;
int sum=0;
int fa[size];
int u[size];
int v[size];
int vis[size];
//int a[size];
void init()
{
	for(int i=0;i<n;i++)
	{
		fa[i]=i;
	}
}
int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y)
{
	int fx=get(x), fy=get(y);
	
	if(fx!=fy)
	{
		fa[fx]=fy;
		sum--;
	}
}
int main()
{
	FAST_IO;
	while(cin>>n>>m)
	{
		sum=n;
		init();
		for(int i=0;i<m;i++)
		{
			cin>>u[i]>>v[i];
		}
		
		for(int i=m-1;i>=0;i--)
		{
			vis[i]=sum;
			merge(u[i],v[i]);
//			for(int j=0;j<n;j++)
//			{
//				a[get(j)]=1;
//			}
//			for(int j=0;j<n;j++)
//			{
//				if(a[j]==1) sum++;
//			}	
//			sum=0;
//			memset(a,0,sizeof(a));	
		}
		for(int i=0;i<m;i++) cout<<vis[i]<<endl;
	}
	return 0;
}
