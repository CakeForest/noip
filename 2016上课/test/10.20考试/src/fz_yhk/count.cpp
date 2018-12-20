#include<cstdio>
#define mod 1000000007
long long ans=0;
int jue(int x)
{
	return x>0 ? x:-x;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,K;
	scanf("%d%d",&n,&K);
	if(K==1)
	{
		for(int i=1;i<=n;i++)
		{
			int ii=n-i;
			ans+=ii*ii;
			ans%=mod;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n-i;j++)
				{
					ans+=j*j;
					ans%=mod;
				}
	}
	
	printf("%lld",ans%mod);
}
/*
					
					for(int k=1+i;k<=n;k++)//i,j为当前点，k，m为找到点 
					{
						if(k==i)continue;
						for(int m=1;m<n;m++)
						{
							if(m==j)continue;
							/*if(j+k-i>n||j+k-i<1)continue;
							if(k+j-m>n||k+j-m<1)continue;
							if(m+k-i>n||m+k-i<1)continue;
							if(i-m+j<1||i+j-m>n)continue;
							
						
						
							else 
							{
								ans++;
								printf("i=%d j=%d k=%d m=%d\n",i,j,k,m);
							}*/
							/*if(j<m)
							{
								if(k+j-m<=n&&m+k-i<=n&&i+j-m<=n&&j+k-i<=n&&k+j-m>=1&&m+k-i>=1&&i+j-m>=1&&j+k-i>=1)
									{
										ans++;
									//	printf("i=%d j=%d k=%d m=%d\n",i,j,k,m);
									}
									
							}
							if(j>m)
							{
								if(i-m+j<=n&&j+k-i<=n&&k-m+j<=n&&m+k-i<=n&&i-m+j>=1&&j+k-i>=1&&k-m+j>=1&&m+k-i>=1)
									{
										ans++;
										//printf("i=%d j=%d k=%d m=%d\n",i,j,k,m);
									}
									
							}
					}
				}*/
