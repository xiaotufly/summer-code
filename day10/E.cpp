#include<iostream>
#include<string>
#include<cstring> 
using namespace std;
const int size=5000000;
int trie[size][33],tot=1;
int t,n,m,h;
//char s1[3100],s2[3100];
long long a[size];
long long d[size];
long long ss[size];
void insert(long long dd)
{
	//int len=strlen(str),
	int p=0;
	for(int k=32;k>=0;k--)
	{
		int ch=(dd>>k)&1;
		if(!trie[p][ch]) trie[p][ch]=++tot;
		p=trie[p][ch];
	}
	d[p]=dd;
}
long long search(long long dd)
{
	//int len=strlen(str),
	int p=0;
	for(int k=32;k>=0;k--)
	{
		int id=(dd>>k)&1;
		if(trie[p][id^1]) p=trie[p][id^1];
		else p=trie[p][id];
	}
	return d[p];
}
int main()
{
	scanf("%d",&t);
	h=1;
	while(t--)
	{
		//memset(ss,0,sizeof(ss));
		//memset(d,0,sizeof(d));
		memset(trie,0,sizeof(trie));
		tot=1;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			insert(a[i]);
		}
		for(int i=0;i<m;i++)
		{
			long long x;
			scanf("%lld",&x);
			ss[i]=search(x);
		}
		cout<<"Case #"<<h<<":"<<endl;
		h++;
		for(int i=0;i<m;i++) printf("%lld\n",ss[i]);
	}
	return 0;
}

