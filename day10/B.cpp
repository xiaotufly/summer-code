#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
int t,n,m;
const int N=1e4+7; 
char s2[1000010],s1[10010];
int len=strlen(s1);
int llen=strlen(s2);
int NEXT[N];
int ans;
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
				ans++;
				//return i-j+1;
			}
		}
		else j=NEXT[j];
	}
	return -1;
}
int main()
{
	FAST_IO;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>s1>>s2;
		len=strlen(s1);
		llen=strlen(s2);
		memset(NEXT,0,sizeof(NEXT));
		getNEXT(); 		
		FirstKmp();
		cout<<ans<<endl;
	}
	return 0;
}
