#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N,P,R,Pg[160],Rune[160],t[160],v[160],f[160][160];

int main()
{
	freopen("pgrune.in","r",stdin);
	freopen("pgrune.out","w",stdout);
	cin>>N>>P>>R;
	for(int i=1;i<=N;i++)
		cin>>Pg[i]>>Rune[i]>>t[i]>>v[i];
	for(int n=1;n<=N;n++)
	{
		if(t[n]==1)//01背包 
			for(int i=P;i>=Pg[n];i--)
				for(int j=R;j>=Rune[n];j--)
					f[i][j]=max(f[i][j],f[i-Pg[n]][j-Rune[n]]+v[n]);
		else if(t[n]==0)//完全背包  
			for(int i=Pg[n];i<=P;i++)
				for(int j=Rune[n];j<=R;j++)
					f[i][j]=max(f[i][j],f[i-Pg[n]][j-Rune[n]]+v[n]);
		else//多重背包 
			for(int i=P;i>=Pg[n];i--)
				for(int j=R;j>=Rune[n];j--)
 					for(int k=0;k<=min(t[n],min(Pg[n]!=0?i/Pg[n]:9999999,Rune[n]!=0?j/Rune[n]:9999999));k++)//血的教训，这里Pg[n]和Rune[n]都有可能为零 
						f[i][j]=max(f[i][j],f[i-k*Pg[n]][j-k*Rune[n]]+k*v[n]);
	
	}
	
	cout<<f[P][R];
	
	return 0;
}
