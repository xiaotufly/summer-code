#include<iostream>
using namespace std;
int main()
{
	long long n,m;
	cin>>n>>m;
	long long max,min;
	long long xx=0;
	if(m!=0)
	{
		min=n-(m*2);
		for(long long i=1;;i++)
		{
			if(m<=(i-1)*i/2)
			{
				xx=i;
				break;
			}	
		}
		if(min<=0) cout<<0<<" ";
		else cout<<min<<" ";
		max=n-xx;
		if(max<=0) cout<<0<<endl;
		else cout<<max<<endl;
	}
	else
	{
		cout<<n<<" "<<n<<endl;
	}
	return 0;
}
