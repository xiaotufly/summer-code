#include<iostream>
using namespace std;
int x[100005];
int y[100005];
int ad[100005];
int main()
{
	int n,m;
	cin>>n>>m;
	int a1=0,a2=0,a3=0,a=0;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
		ad[x[i]]++;
		ad[y[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(ad[i]==1)
		{
			a1++;
		}
		else if(ad[i]==2)
		{
			a2++; 
		}
		else
		{
			a3++;
			a=ad[i];
		}
	}
	if(a1==2&&a2==m-1) cout<<"bus topology"<<endl;
	else if(a2==n) cout<<"ring topology"<<endl;
	else if(a1==m&&a3==1&&a==m) cout<<"star topology"<<endl;
	else cout<<"unknown topology"<<endl;
	return 0;
 } 
