#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE=120;
int n,a[MAXSIZE],f[MAXSIZE][MAXSIZE],input[MAXSIZE],mmax=-1;

int main(){
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
	
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&input[i]);
	for(int s=1;s<=n;s++)
	{
		int len=1;
		while(len<=n)//枚举不同情况 
		{
			a[s]=input[len++];
			s=s+1>n?1:s+1;
		}
		a[n+1]=a[1];
		
		for(int len=3;len<=n+1;len++)//一共有len-1个珠子  
		{
			for(int i=1;i<=n-len+2;i++)//头标记为i 
			{
				int j=i+len-1;//尾标记为j 
				f[i][j]=-1;
				for(int m=i+1;m<=j-1;m++)//中间的标记为m 
					f[i][j]=max(f[i][j],f[i][m]+f[m][j]+a[i]*a[m]*a[j]);
			}
		}
		mmax=max(mmax,f[1][n+1]);
		
	}
	printf("%d",mmax);
	
	
	return 0;
}
