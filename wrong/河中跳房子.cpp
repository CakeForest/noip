#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int l,n,m,a[50020]={0},dis=1000000000,ans;
int work(int t)//测试每次所需移动的石头数量  t:最小距离 
{
	/*int sum;
	for(int i=0;i<=n;)
	{
		int j;
		for(j=i+2;j<=n+1;j++)
		{
			if(a[j]-a[i]>=t)
			{
				sum+=j-i-2;
				break;
			}
		}
		i=j-1;
	}
	return sum;*/
	
	int now=0,ans=0;
	for (int i=1;i<=n;i++)
		if (a[i]-now>=t){
			ans++;
		now=a[i];
	}
	if (l-now<t) ans--;
		return ans;
	
	
	
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d %d %d",&l,&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1]=l;
	int s=1,e=l;
	while(s<=e)
	{
		int mid=(s+e)/2+1,j;
		j=work(mid);
	//	printf("-------j=%d s=%d e=%d mid=%d\n",j,s,e,mid);
		if(j>m)
			s=mid;
		else if(j<=m)
			e=mid-1;
		if(s==e)
		{
			ans=e;
			break;
		}
	}
	printf("%d",ans);
	return 0;
}
