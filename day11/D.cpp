#include<iostream>
#include<cstdio>
#include<string>
#include<cstring> 
using namespace std;
const int size=500000;
int trie[size][30],tot=1;
char ss[5000][30];
int t,h;
char s1[31];
int d[size];
int ans;
void insert(char* str)
{	
	int len=strlen(str);int p=1;
	for(int k=0;k<len;k++)
	{
		int ch=str[k]-'a';
		if(trie[p][ch]==0) trie[p][ch]=++tot;
		d[p]++;
		p=trie[p][ch];
		if(k==len-1) d[p]++;
	}
	//cout<<d[p]<<endl;
}
void search(char* str)
{
	int len=strlen(str);
	int p=1;
	for(int k=0;k<len;k++)
	{
		p=trie[p][str[k]-'a'];
		if(d[p]==1||k==len-1)
		{
			cout<<str[k]<<endl;
			return ;
		}
		cout<<str[k];
		//if(p==0) return false;
	}
	
}
int main()
{
	while(gets(s1))
	{
		strcpy(ss[h],s1);
		//ss[h]=s1;
		h++;
		if(s1[0]=='\0') break;
		insert(s1);
	}
	for(int i=0;i<h;i++)
	{
		cout<<ss[i]<<" ";
		memset(s1,0,sizeof(s1));
		for(int j=0;j<strlen(ss[i]);j++)
		{
			s1[j]=ss[i][j];
		}
		search(s1);
	}
//while(gets(s1))
//	{
//		if(s1[0]=='\0') break;
//		insert(s1);
//	}
//	while(gets(s2))
//	{
//		ans=0;
//		if(s2[0]=='\0') break;
//		search(s2);
//		//cout<<ans<<endl;
//	}
	return 0;
}
