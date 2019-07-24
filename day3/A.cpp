#include<iostream>
using namespace std;
const int size=500005;
int fa[size];
int a[size];
int n,m;
int vis[size];
int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y)
{
	fa[get(x)]=get(y);
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
int main()
{
	
	cin>>n>>m;
	init();
	while(m--)
	{
		int x;
		cin>>x;
		int z;
		int f=0;
		for(int i=1;i<=x;i++)
		{
			cin>>vis[i];
			if(f==0)
			{
				z=vis[i];
				f=1;
			}
			else
			merge(z,vis[i]);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		a[get(i)]++;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[get(i)];
		if(i!=n) cout<<" ";
	}
	cout<<endl;
	return 0;
}
