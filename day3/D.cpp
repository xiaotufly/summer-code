#include<iostream>
#include<algorithm>
using namespace std;
const int size=1000005;
int n,m;
int fa[size];
int ii[size];
int jj[size];
int ee[size];
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
void discrete(int a[],int b[])
{
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(i==1||a[1]!=a[i-1]) b[++m]=a[i]; 
}
void query(int x,int b[])
{
	return lower_bound(b+1,b+m+1,x)-b;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>ii[i]>>jj[i]>>ee[i];
		}
		for(int i=1;i<=n;i++)
		{
			
		}
	}
	return 0;
}
