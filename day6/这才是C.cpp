#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
const int size=2000;
int m[size][size];
int match[size];
int vis[size];
vector<int> graph[size];
int u[size];//�Ƿ���Уѧ�� 
int v[size];//�Ƿ�ؼ�
int f[size];//��Ҫ˯������ 
int n,ans,sum;
bool dfs(int x)
{
	int y;
	for(int i=0;i<graph[x].size();i++)
		if(!vis[y=graph[x][i]])
		{
			vis[y]=1;
			if(!match[y]||dfs(match[y]))
			{
				match[y]=x;
				return true;				
			}
		}
	return false;
}//����ƥ�� 

void add(int x,int y)
{
	graph[x].push_back(y);
}//��� 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(match,0,sizeof(match));
		memset(graph,0,sizeof(graph));
		memset(vis,0,sizeof(vis));
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		ans=0;
		sum=0;
		//��ʼ�� 
		cin>>n;
		for(int i=1;i<=n;i++) cin>>u[i];//�Ƿ���У 
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];//�Ƿ�ؼ� 
			if(u[i])//�������У�� 
			{
				if(!v[i])//������ؼ� 
				{
					f[i]=1;//Ҫ˯����� 
					sum++;//Ҫ˯���������� 
				}
			}
			if(!u[i])//���������У�� 
			{
				 f[i]=1;//Ҫ˯�����
				 sum++;//Ҫ˯���������� 
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(u[i]&&f[i]) add(i,i);
		} 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>m[i][j];
				if(m[i][j]&&f[i]&&u[j])
				{
					add(i,j);
					//cout<<i<<" "<<j<<endl;
					//cout<<i<<" "<<j<<endl;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		if(ans==sum) cout<<"^_^"<<endl;
		else cout<<"T_T"<<endl;
	}
	return 0;
}

