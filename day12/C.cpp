#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
const int size=5e5+100;
long long  t,n,a[size];
priority_queue <long long,vector<long long>,greater<long long> > q;
int main()
{
	cin>>t;
	while(t--)
	{
		while(!q.empty()) q.pop();
		cin>>n;
		//int mx=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			q.push(x);
		}
		long long root=0;
		int i=1;
		
		while(q.size()>1)
		{
			long long a=q.top();
			q.pop();
			long long b=q.top();
			q.pop();
			root+=a+b;
			q.push(a+b);
//			if(i%2==1&&q.size()-1!=0&&i!=1) root+=mx;
//			if(q.size()-1!=0) mx-=q.top();
//			root-=q.top();
//			q.pop();
//			i++; 
		}
		cout<<root<<endl;
		if(t!=0) cout<<endl;
	
	}
	return 0;
}
