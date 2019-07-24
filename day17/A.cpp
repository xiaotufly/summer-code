#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll arr[50010];
struct segt
{
	ll *a;
	struct Tree
	{
		int l,r;
		ll sum,lz,max,min;
		void update(ll v)
		{
			sum+=v*(r-l+1);
			lz+=v;
			max+=v;
			min+=v;
		}
	}tree[500000];
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
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		string s;
		for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
		tr.modify(arr);
		tr.build(1,1,n);
		cout<<"Case "<<h<<":"<<endl;
		h++;
		while(cin>>s)
		{	
			
			if(s=="Query")
			{
				int x,y;
				scanf("%d%d",&x,&y);//cout<<x<<" "<<y;
				cout<<tr.querySUM(1,x,y)<<endl;	
			}
			else if(s=="Add")
			{
				int x,y;
				scanf("%d%d",&x,&y);
				tr.updateADD(1,x,x,y);
			}
			else if(s=="Sub")
			{
				int x,y;
				scanf("%d%d",&x,&y);
				tr.updateADD(1,x,x,-y);
			}
			else if(s=="End") break;		
		}
	}
	return 0;
} 
