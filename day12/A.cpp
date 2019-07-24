#include<iostream>
#include<string>
#include<cstring>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
const int size=110100;
int p[size*2];
char s[size*2],ss[size*2];
int len;
void manacher()
{
	int i;
	ss[0]='$';
	ss[1]='#';
	for(i=0;i<strlen(s);i++)
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
		else p[i]=1;
		while(ss[i+p[i]]==ss[i-p[i]]) p[i]++;
		if(p[i]+i>p[id]+id) id=i;
		if(p[i]-1>maxl) maxl=p[i]-1;
		//cout<<maxl<<endl;
	}
	cout<<maxl<<endl;
}
int main()
{
	FAST_IO;
	while(cin>>s)
	{
		manacher();
	}
	return 0;
}
