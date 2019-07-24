#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int size=1e5+5;
int v[size];
long long a,b;
int color;
vector<int>graph[size];
void add(int x,int y)
{
	graph[x].push_back(y);
}//´æ 
void dfs(int x,int color)
{
	v[x]=color;
	for(int i=0;i<graph[x].size();i++)
	{
		int y=graph[x][i];
		if(v[y]==0) dfs(y,3-color);
	}
}//È¾É« 
int main()
{
	int n;
	cin>>n;
	int x,y;
	for(int i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}//´æÍ¼ 
	for(int i=1;i<=n;i++)
	{
		if(v[i] == 0)dfs(i,1);
	}//È¾É«
	for(int i=1;i<=n;i++)
	{
		if(v[i]==1) a++;
		else if(v[i]==2) b++;
	} //Ñ°ÕÒÑÕÉ«ÊýÁ¿
	cout<<a*b- n +1<<endl; 
	return 0;
}
//#include <iostream>
//#include <vector>
//using namespace std;
//const int N = 1e5+5;
//vector <int> V[N];
//int v[N]; 
//int n, m, f;
//void add(x, y){
//	V[x].push_back(y);
//}
//
//void dfs(int x, int c){
//	v[x] = c;
//	for(int i = 0; i < V[x].size(); i++){
//		int y = V[x][i];
//		if(v[y] == 0) dfs(y, 3-c);
////		else if(v[y] == c){
////			f = 1;
////			return ;
////		}
//	}
//}
//
//int main(){
//	
//	
//	
//	
//	f = 0;
//	for(int i = 1; i <= n; i++){
//		if(v[i] == 0) dfs(i, 1);
//	}
//	
//	if(f == 1) {
//		
//	}
//	return 0;
//}
//
//























