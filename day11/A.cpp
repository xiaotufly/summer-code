#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int ans;
int t;
char s[1000];
int Get_min()
{
    int n=strlen(s);
    int i=0,j=1,k=0,t;
    while(i<n&&j<n&&k<n)
    {
        t=s[(i+k)%n]-s[(j+k)%n];
        if(!t) k++;
        else
        {
            if(t>0) i+= k+1;
            else j+=k+1;
            if(i==j) j++;
            k=0;
        }
    }
    return i>j?j:i;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<Get_min()+1<<endl;
	}
	return 0;
} 
