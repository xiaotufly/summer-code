#include<iostream>
using namespace std;
int n,k;
int a[200005];
int pos[200005];
struct node
{
	int value;
	int pre,next;
}nod[200005];
int head,tail,tot,p;

void init()
{
	head=1;
	tail=2;
	tot=2;
	nod[head].next=tail;
	nod[tail].pre=head;
}

int insert(int p,int val)
{
	int q=++tot;
	nod[q]=node({val,p,nod[p].next});
	nod[nod[p].next].pre=q;
	nod[q].next=q;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		pos[a[i]]=insert(head,i);
	}
	int c=1;
	while(p!=0)
	{
		
	}
	return 0;
} 
