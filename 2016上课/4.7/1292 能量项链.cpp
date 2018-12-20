#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=120;
int n,a[MAXSIZE],f[MAXSIZE][MAXSIZE],input[MAXSIZE],mmax=-1;
//f[i][j]表示从i到j个珠子所释放的能量 
int main()
{
//	freopen("in.txt","r",stdin);
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
		
		/*这道题的关键是，程序枚举的是珠子的头尾，而答案是求珠子聚合后的能量，所以
 		最后的最大值应该存在f[1][n+1]中*/
		
		for(int len=3;len<=n+1;len++)//一共有len-1个珠子  
		{
			for(int i=1;i<=n-len+2;i++)//头标记为i 
			{
				int j=i+len-1;//尾标记为j 
				f[i][j]=-1;
				for(int m=i+1;m<=j-1;m++)//关键，m从i+1枚举到j 中间的标记为m 
					f[i][j]=max(f[i][j],f[i][m]+f[m][j]+a[i]*a[m]*a[j]);
			}
		}
		mmax=max(mmax,f[1][n+1]);
		
	}
	printf("%d",mmax);
	
	return 0;
}
