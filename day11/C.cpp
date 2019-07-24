#include<iostream>
#include<cstdio>
#include<string>
#include<cstring> 
using namespace std;
const int size=500000;
int trie[size][30],tot=1;
int t;
char s1[31],s2[size];
int d[size];
int ans;
void insert(char* str)
{	
	int len=strlen(str),p=1;
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
int search(char* str)
{
	int len=strlen(str),p=1;
	for(int k=0;k<len;k++)
	{
		p=trie[p][str[k]-'a'];
		if(p==0) return false;
	}
	return d[p];
}
int main()
{
	while(gets(s1))
	{
		if(s1[0]=='\0') break;
		insert(s1);
	}
	while(gets(s2))
	{
		ans=0;
		if(s2[0]=='\0') break;
		cout<<search(s2)<<endl;
		//cout<<ans<<endl;
	}
	return 0;
}
