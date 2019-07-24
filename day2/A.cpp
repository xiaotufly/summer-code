#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define size 10005
int n,pre[size],in[size];
vector<int>a;
struct node
{
	int value;
	node *le,*re;
node(int value):value(value),le(NULL),re(NULL)
{
	
};
};
/*struct t
{
	node *root;
};*/
node *buildtree(int prel,int prer,int inl,int inr)
{
	if(prel>prer||inl>inr) return NULL;
	node *tmp=new node(pre[prel]);
	int i;
	for(i=inl;i<=inr;i++)
	{
		if(in[i]==pre[prel]) break;
	}
	int nn;
	nn=i-inl;
	//cout<<i<<" "<<nn<<endl;
	tmp->le=buildtree(prel+1,prel+nn,inl,i-1);
	//cout<<prel+1<<" "<<prel+nn<<" "<<inl<<" "<<i-1<<endl;
	tmp->re=buildtree(prel+nn+1,prer,i+1,inr);
	return tmp;
}
void behind(node *root)
{
	if(!root) return ;
	behind(root->le);
	behind(root->re);
	a.push_back(root->value);
}
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;i++) cin>>pre[i];
		for(int i=0;i<n;i++) cin>>in[i];
		//t tree;
		//tree.root=buildtree(0,n-1,0,n-1);
		
		node* root = buildtree(0,n-1,0,n-1);
		behind(root);
		//behind(tree.root);
		for(int i=0;i<n;i++)
		{
			cout<<a[i];
			if(i!=n-1) cout<<" ";
		}
		cout<<endl;
		a.clear();
	}
	return 0;
}
