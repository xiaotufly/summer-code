#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;//��ll 
ll n,m;//�½硢�Ͻ� 
int a[25];//��ÿһλ���� 
ll dp[25][25];//��λdp 
ll dfs(ll pos,ll state,ll limit)//posΪλ����state��ʾǰһλ�Ƿ�Ϊ6��limit��ʾ�Ƿ����Ͻ� 
{
	if(pos==0) return 1;//�������� 
	if(!limit&&dp[pos][state]!=-1) return dp[pos][state];//���û�������ұ����� �ͷ������ ����ɾ�� ��������̼���ʱ��  
	ll up=limit?a[pos]:9;//���Ͻ���Ϊpos ���Ͻ�������Ϊ9 
	ll ans=0;//��������� 
	for(int i=0;i<=up;i++)//���Ͻ���� 
	{
		if(state&&i==3) continue;//ǰһλ��6 ������һλ��2 
		//if(i==4) continue;//��һλ��4 
		ans+=dfs(pos-1,i==1,limit&&i==up);
		//ans:���������� pos-1:λ����һ i==6:�ж���һλ�Ƿ�Ϊ6  
		//limit&&i==up��������λ���������λ �� ǰһλû�б��������������ʱ ������ǲ��������Ƶ� 
	}
	if(!limit) dp[pos][state]=ans;
	//���û������ Ҳ����ǰһλû�б�������������� �Ǿ͸�ֵ ����ʱ�� ����ɾ�� 
	return ans;
}
ll solve(ll x)
{
	memset(dp,-1,sizeof(dp));//��ʼ��dp Ϊδ����
	ll top=0;//���� 
	while(x)//��xÿһλ���ֽ���ȥ�� �˳� 
	{
		a[++top]=x%10;
		x/=10;
	}
	return dfs(top,0,1);//����dfs ��ֵΪ ����λ�� ǰһλ��Ϊ6 ���Ͻ� 
}
int main()
{
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		cout<<solve(n-1)<<endl;//��Ϊÿ�λ��0��ʼ������Ҫ��ȥ�������֮ǰ���� 
	}
	return 0;
}
