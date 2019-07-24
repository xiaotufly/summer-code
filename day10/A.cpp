#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
int t,n,m;
const int N=1e4+7; 
int s2[1000010],s1[10010];
int len=m;
int llen=n;
int NEXT[N];
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
int FirstKmp()
{
	int i=0,j=0;
	while(i<llen)
	{
		if(j==-1||s1[j]==s2[i])
		{
			i++;j++;
			if(j==len)
			{
				return i-j+1;
			}
		}
		else j=NEXT[j];
	}
	return -1;
}
int main()
{
	cin>>t;
	while(t--)
	{
		memset(NEXT,0,sizeof(NEXT));
		cin>>n>>m;
		for(int i=0;i<n;i++) scanf("%d",&s2[i]);
		for(int i=0;i<m;i++)scanf("%d",&s1[i]);
		len=m;
		llen=n;
		memset(NEXT,0,sizeof(NEXT));
		getNEXT(); 
		int t=FirstKmp();
		cout<<t<<endl;
	}
	return 0;
}
