#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;//简化ll 
ll n,m;//下界、上界 
int a[25];//存每一位数字 
ll dp[25][25];//数位dp 
ll dfs(ll pos,ll state,ll limit)//pos为位数，state表示前一位是否为6，limit表示是否有上界 
{
	if(pos==0) return 1;//遍历结束 
	if(!limit&&dp[pos][state]!=-1) return dp[pos][state];//如果没有限制且被访问 就返回这个 可以删掉 这个是缩短计算时间  
	ll up=limit?a[pos]:9;//有上界则为pos 无上界限制则为9 
	ll ans=0;//可行数结果 
	for(int i=0;i<=up;i++)//到上界结束 
	{
		if(state&&i==3) continue;//前一位是6 并且这一位是2 
		//if(i==4) continue;//这一位是4 
		ans+=dfs(pos-1,i==1,limit&&i==up);
		//ans:可行数增加 pos-1:位数减一 i==6:判断这一位是否为6  
		//limit&&i==up：如果这个位数不是最高位 且 前一位没有遍历到最大限制数时 这个数是不会有限制的 
	}
	if(!limit) dp[pos][state]=ans;
	//如果没有限制 也就是前一位没有遍历到最大限制数 那就赋值 缩短时间 可以删掉 
	return ans;
}
ll solve(ll x)
{
	memset(dp,-1,sizeof(dp));//初始化dp 为未访问
	ll top=0;//计数 
	while(x)//当x每一位被分解存进去后 退出 
	{
		a[++top]=x%10;
		x/=10;
	}
	return dfs(top,0,1);//调用dfs 传值为 数字位数 前一位不为6 有上界 
}
int main()
{
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		cout<<solve(n-1)<<endl;//因为每次会从0开始，所以要减去最低限制之前的数 
	}
	return 0;
}
