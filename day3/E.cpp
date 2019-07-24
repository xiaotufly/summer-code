#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct rec
{
	int x,y,z;
}edge[105];
int fa[105],ans;
int dad[106];
bool operator<(rec a,rec b)
{
	return a.z<b.z;
}

int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
/*void merge(int x,int y)
{
	fa[get(x)]=get(y);
}*/
//void init()
//{
//	for(int i=1;i<=m;i++)
//	{
//		fa[i]=i;
//	}
//}
int main()
{
	while(cin>>n>>m)
	{
		int f=0;
		if(n==0) break;
		else 
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].z);
				//merge(edge[i].x,edge[i].y);
			}
			sort(edge+1,edge+n+1);
			for(int i=1;i<=m;i++) fa[i]=i;
			for(int i=1;i<=n;i++)
			{
				int x=get(edge[i].x);
				int y=get(edge[i].y);
				if(x==y) continue;
				fa[x]=y;
				ans+=edge[i].z;
			}
			int pp=get(1);
			for(int i=2;i<=m;i++)
			{
				if(pp!=get(i))
				{
					f=1;
					break;
				}
			//	cout<<get(i)<<endl;
			}
			if(f!=1) cout<<ans<<endl;	
			else cout<<"?"<<endl;
		}
		ans=0;
	}
	return 0;
}
