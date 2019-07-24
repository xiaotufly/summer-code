#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
int t,m;
char s1[100010];
int NEXT[100010];
int ans;
int llen;
int len;
void getNEXT()
{
	int i=0;
	int j=NEXT[0]=-1;
	while(i<len)
	{
		if(j==-1||s1[i]==s1[j])
		{
			i++;
			j++;
			NEXT[i]=j;
		}
		else
		{
			j=NEXT[j];
		}
	}
}
int main()
{
	FAST_IO;
	cin>>t;
	while(t--)
	{
		cin>>s1;
		len=strlen(s1);
		ans=0;
		getNEXT(); 
		llen=len-NEXT[len];
		if(llen==len)cout<<len<<endl;
		else if(len%llen==0)cout<<0<<endl;
		else cout<<llen-len%llen<<endl;
	}
	return 0;
}
