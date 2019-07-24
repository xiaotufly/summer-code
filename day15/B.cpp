#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int size=150010;
int p;
int a[size];
int main()
{
	cin>>p;
	int ans=1;
	int sum=0;
	for(int i=1;i<=p;i++) cin>>a[i];
	for(int i=1;i<=p;i++)
	{
		if(ans%2==1&&i!=p)
		{
			if(a[i]>=a[i+1])
			{
				sum+=a[i];
				ans++;
			}
		}
		else if(ans%2==0&&i!=p)
		{
			if(a[i]<=a[i+1])
			{
				sum-=a[i];
				ans++;
			}
		}
		if(i==p&&ans%2==1) sum+=a[i];
	}
	cout<<sum<<endl;
	return 0;
}
