#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int ans[20000]={2};//至少从2开始乘 
int sum;
void work(int k,int loc)
{
	if(k==1)
		sum++;//如果k=1，表明已经分解完，符合条件 
	else
		for(int i=ans[loc-1];i<=k;i++)//下一个数必须大于等于上一个数 
			if(k%i==0)//如果可以整除 
			{
				ans[loc]=i;//此位设为i 
				work(k/i,loc+1);//枚举下一个因数 
			}
}

int main()
{
	int n,a[2000];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		sum=0;
		work(a[i],1);
		printf("%d",sum);
		if(i!=n)
			printf("\n");
	}
}
