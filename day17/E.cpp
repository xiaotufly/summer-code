#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
typedef long long ll;
int m,n;
ll arr[500100];
int vis[500100];
struct segt
{
	ll *a;
	struct Tree
	{
		int l,r;
		ll sum,lz,max,min;
		void update(ll v)
		{
			sum=v*(r-l+1);
			lz=0;
			max+=v;
			min+=v;
		}
	}tree[500100];
	void modify(ll *arr)
	{
		a=arr;
	}
	void pushup(int x)
	{
		tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
		tree[x].max=max(tree[2*x].max,tree[2*x+1].max);
		tree[x].min=min(tree[2*x].min,tree[2*x+1].min);
	}
	void pushdown(int x)
	{
		if(tree[x].lz!=0)
		{
			tree[2*x].update(tree[x].lz);
			tree[2*x+1].update(tree[x].lz);
			tree[x].lz=0;
		}
	}
	void build(int x,int l,int r)
	{
		tree[x].l=l;
		tree[x].r=r;
		tree[x].sum=tree[x].max=tree[x].min=tree[x].lz=0;
		if(l==r)
		{
			tree[x].sum=tree[x].max=tree[x].min=a[l];
			return ;
		}
		int mid=(l+r)/2;
		build(2*x,l,mid);
		build(2*x+1,mid+1,r);
		pushup(x);
	}
	void updateADD(int x,int l,int r,ll c)
	{
		int L=tree[x].l;
		int R=tree[x].r;
		int mid=(L+R)/2;
		if(tree[x].sum == (R-L+1)) return;
		if((l<=L)&&(r>=R)&&(L==R))
		{
			tree[x].sum=sqrt(tree[x].sum);
			//tree[x].update(c);
			return ;
		}
		//pushdown(x);
		if(l<=mid) updateADD(2*x,l,r,c);
		if(r>mid) updateADD(2*x+1,l,r,c);
		pushup(x); 
	}
	ll querySUM(int x,int l,int r)
	{
		int L=tree[x].l;
		int R=tree[x].r;
		int mid=(L+R)/2;
		ll res=0;
		//cout << L << ' ' << R << endl;
		if((l<=L)&&(r>=R))
		{
			return tree[x].sum;
		}
		//pushdown(x);
		if(l<=mid) res+=querySUM(2*x,l,r);
		if(r>mid) res+=querySUM(2*x+1,l,r);
		pushup(x);
		return res;
	}
	ll SUM ,MAX,MIN;
	void query(int x,int l,int r)
	{
		int L=tree[x].l;
		int R=tree[x].r;
		int mid=(L+R)/2;
		if((l<=L)&&(r>=R))
		{
			SUM+=tree[x].sum;
			MAX=max(MAX,tree[x].max);
			MIN=min(MIN,tree[x].min);
			return ;
		}
		pushdown(x);
		if(l<=mid) query(2*x,l,r);
		if(r>mid) query(2*x+1,l,r);
		pushup(x);
	}
}tr;
int main()
{
	int h=1;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&arr[i]);
			if(arr[i]==1) vis[i]=1;
		}
		tr.modify(arr);
		scanf("%d",&m);
		tr.build(1,1,n);
		printf("Case #%d:\n",h);
		h++;
		while(m--)
		{	
			int t,x,y;
			scanf("%d%d%d",&t,&x,&y);
			if(x>y)
			{
				int tt=x;
				x=y;
				y=x;
			}
			if(t==1)
			{
				printf("%lld\n",tr.querySUM(1,x,y));
			}
			else 
			{
				tr.updateADD(1,x,y,0);
//				for(int i=x;i<=y;i++)
//				{
//					ll w=sqrt(tr.a[i]);
//					if(tr.a[i]!=1)
//					{
//						tr.a[i]=w;
//						//cout<<"QWQ"<<endl;
//						tr.updateADD(1,i,i,w);
//					} 	
//				}
			}		
		}
		printf("\n");
	}
	return 0;
} 
