//#include<iostream>
//#include<string>
//#include<cstring>
//using namespace std;
//#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
//int t,n,m;
//const int N=1e4+7; 
//char s2[1000010],s1[10010];
//int len=strlen(s1);
//int llen=strlen(s2);
//int NEXT[N];
//int ans;
//void getNEXT()
//{
//	int i=0;
//	int j=NEXT[0]=-1;
//	while(i<len)
//	{
//		if(j==-1||s1[i]==s1[j])
//		{
//			i++;
//			j++;
//			NEXT[i+1]=j;
//		}
//		else
//		{
//			j=NEXT[j];
//		}
//	}
//}
//int FirstKmp()
//{
//	int i=0,j=0;
//	while(i<llen)
//	{
//		if(j==-1||s1[j]==s2[i])
//		{
//			i++;j++;
//			if(j==len)
//			{
//				//i++;
//				ans++;
//				//i+=len-1;
//				//j+=len;
//				//return i-j+1;
//			}
//		}
//		else j=NEXT[j];
//	}
//	return -1;
//}
//int main()
//{
//	FAST_IO;
//	string s="#";
//	while(cin>>s2)
//	{
//		if(s2==s) return 0;
//		//cout<<s2;
//		cin>>s1;
//		ans=0;
//		len=strlen(s1);
//		llen=strlen(s2);
//		memset(NEXT,0,sizeof(NEXT));
//		getNEXT(); 
//		FirstKmp();
//		cout<<ans<<endl;
//	}
//	return 0;
//}
#include<iostream>
using namespace std;
int main()
{
	unsigned long long sum1=9000000000000000000*4;
	//cout<<sum1*4<<endl;	
	cout<<sum1<<endl;

}
