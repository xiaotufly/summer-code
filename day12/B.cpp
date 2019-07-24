#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int size=1e7*4;
char ss1[size],ss2[size],s1[size],s2[size];
int p[size];
int len;
void manacher(char ss[],char s[])
{
	int i;
	ss[0]='$';
	ss[1]='#';
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		ss[i*2+2]=s[i];
		ss[i*2+3]='#';
	}
	len=i*2+2;
	ss[len]='\0';
	int maxl,id=0;
	maxl=0;
	memset(p,0,sizeof(p));
	for(i=0;i<len;i++)
	{
		if(p[id]+id>i)	p[i]=min(p[2*id-i],p[id]+id-i);
		else
		{
			p[i]=1;
		}
		while(ss[i+p[i]]==ss[i-p[i]]) p[i]++;
		if(p[i]+i>p[id]+id) id=i;
		if(p[i]-1>maxl) maxl=p[i]-1;
		//cout<<maxl<<endl;
	}
	cout<<maxl<<endl;
}
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>s1>>s2;
		int n=strlen(s1);
		int f=0;
		for(int i=0;i<n;i++)
		{
			if(s1[i]=s2[i])
			{
				f=1;break;
			}
		}
	}
	return 0;
}
