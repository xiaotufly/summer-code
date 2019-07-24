#include<iostream>
#include<cmath>
using namespace std;
int p[2005];
int main()
{
	int n;
	cin>>n;
	int sum=0;
	int pp=0;
	int m=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=n;i++)
	{
		pp=i;
		sum=0;
		while(pp!=-1)
		{
			pp=p[pp];
			sum++;		
		}
		m=max(m,sum);
	}
	cout<<m<<endl;
	return 0;
}
