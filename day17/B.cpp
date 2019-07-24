#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
int t,n,m;
ll arr[5000100];
struct segt
{
	ll *a;
	struct Tree
	{
		int l,r;
		ll sum,lz,max,min;
		void update(ll v)
		{
			sum=v;
			lz=0;
			max=v;
			min=v;
		}
	}tree[5001000];
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
		//cout << l << ' ' << r << endl;
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
		if((l<=L)&&(r>=R))
		{
			tree[x].update(c);
			return ;
		}
		pushdown(x);
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
		pushdown(x);
		if(l<=mid) res+=querySUM(2*x,l,r);
		if(r>mid) res+=querySUM(2*x+1,l,r);
		pushup(x);
		return res;
	}
	ll queryMAX(int x,int l,int r)
	{
		int L=tree[x].l;
		int R=tree[x].r;
		int mid=(L+R)/2;
		ll res=-INF;
		if((l<=L)&&(r>=R))
		{
			return tree[x].max;
		}
		pushdown(x);
		if(l<=mid) res=max(res,queryMAX(2*x,l,r));
		if(r>mid) res=max(res,queryMAX(2*x+1,l,r));
		pushup(x);
		return res;
	}
	ll queryMIN(int x,int l,int r)
	{
		int L=tree[x].l;
		int R=tree[x].r;
		int mid=(L+R)/2;
		ll res=INF;
		if((l<=L)&&(r>=R))
		{
			return tree[x].min;
		}
		pushdown(x);
		if(l<=mid) res=min(res,queryMAX(2*x,l,r));
		if(r>mid) res=min(res,queryMAX(2*x+1,l,r));
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
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		
		string s;
		for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
		tr.modify(arr);
		tr.build(1,1,n);
		while(m--)
		{	
			cin>>s;
			if(s=="Q")
			{
				int x,y;
				scanf("%d%d",&x,&y);//cout<<x<<" "<<y;
				cout<<tr.queryMAX(1,x,y)<<endl;	
			}
			else if(s=="U")
			{
				int x,y;
				scanf("%d%d",&x,&y);
				//tr.updateADD(1,x,x,0);
				tr.updateADD(1,x,x,y);
			}
		}
	}
	return 0;
} 
