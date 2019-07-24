#include<iostream>
#include<cstring>
#define bug cout << "!!!" << endl;
using namespace std;
int wid[200005];
int vis[200005];
int n,k,x,f;
int all;
struct node
{
	int value;
	int prev,next;
}node[200005];
int head,tail,tot;
void initialize()
{
	tot=2;
	head=1,tail=2;
	node[head].next=tail;
	node[tail].prev=head;
}
void insert(int p,int val)
{
	int q=++tot;
	node[q].value=val;
	node[node[p].next].value=val;
	node[q].next=node[p].next;
	node[p].next=q;
	node[q].prev=p;
}
void remove(int p)
{
	node[node[p].prev].next=node[p].next;
	node[node[p].next].prev=node[p].prev;
}
void recycle()
{
	memset(node,0,sizeof(node));
	head=tail=tot=0;
}
void search(int f)
{
	int q=head;
	int index;
	int ans=0;
	int sum=0;
	int xx=0;
	while(q!=tail)
	{
		q=node[q].next;
		sum=node[q].value;
		if(sum>ans)
		{
			ans=sum;
			index=q;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]==ans)
		{
			xx=i;
			break;
		}
	}
	int w=index;
	int x1=0;
	for(int i=xx;;i++)
	{	
	if(x1==k+1) break;
		if(wid[i]==0) 
		{	
			wid[i]=f;
			all--;
			remove(w);
			w=node[w].next;
			cout<<i<<" "<<wid[i]<<endl;
			x1++;
		} 
		if(i+1>n-1) break;
	}
	all++;
	int x2=0;
	for(int i=xx;;i--)
	{
		if(x2==k) break;
		if(wid[i]==0)
		{	
			wid[i]=f;
			all--;
			remove(index);
			index=node[index].prev;
			cout<<i<<" "<<wid[i]<<endl;
			x2++;
		}
		if(i-1<0) break;
	}
	for(int i=0;i<n;i++)
	{
		cout<<wid[i]<<" ";
	}
}
int main()
{
	initialize();
	cin>>n>>k;
	all=n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		vis[i]=x;
		insert(head,x);
	}
	for(int i=0;i<n;i++)
	{
		if(all==0) break;
		if((i+1)%2==0) f=2;
		else f=1;
		bug
		search(f);
		if(all==0) break;
	}
	for(int i=0;i<n;i++)
	{
		cout<<wid[i]<<" ";
	}
	cout<<endl;
	recycle();
	return 0;
}
