#include<iostream>
using namespace std;
int a[0x3f3f];
int b[0x3f3f];
int main()
{
	int n;
	string p1="push";
	string p2="pop";
	string m="merge";
	char a='A';
	char b='B';
	int i=1;
	string t;
	char ab;
	int x;
	int aa=0;
	int bb=0;
	while(cin>>n)
	{
		cout<<"Case #"<<i<<":"<<endl; 
		i++;
		aa=0;
		bb=0;
		while(n--)
		{
			cin>>t;
			cin>>ab;
			if(t=="push")
			{
				cin>>x;
				if(ab=='A') a[aa++]=x;
				else if(ab=='B') b[bb++]=x;
			}
			else if(t=="pop")
			{
				if(ab=='A') cout<<a[aa--]<<endl;
				else if(ab)
			}
			else if(t=="merge")
			{
				
			}
		}
		
	}
	return 0;
}
