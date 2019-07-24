#include<iostream>
#include<string>
#include<cstring> 
using namespace std;
const int size=10000;
int trie[size][5],tot=1;
int t;
char s1[3100],s2[3100];
int d[3100];
void insert(char* str)
{
	
	int len=strlen(str),p=1;
	for(int k=0;k<len;k++)
	{
		int ch=str[k]-'0';
		if(trie[p][ch]==0) trie[p][ch]=++tot;
		p=trie[p][ch];
	}
	d[p]=1;
	cout<<p<<endl;
}
bool search(char* str)
{
	int len=strlen(str),p=1;
	for(int k=0;k<len;k++)
	{
		p=trie[p][str[k]-'0'];
		if(p==0) return false;
	}
	cout<<p<<endl;
	return d[p];
}
int main()
{
	cin>>t;
	while(t--)
	{
		memset(d,0,sizeof(d));
		cin>>s1>>s2;
		insert(s1);
		if(search(s2))cout<<"same"<<endl;
		else cout<<"different"<<endl;
	}
	return 0;
}
