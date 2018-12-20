#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int m,n,r,s;//m,r为x   r,s为y 
	int a[120][120],b[120][120];
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j][i]);
	scanf("%d %d",&r,&s);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=s;j++)
			scanf("%d",&b[j][i]);//读取矩阵 
	
	int min=429496729; int logx,logy;
	int sum=0;//枚举所有可能
	for(int i=1;i<=m-r+1;i++) //j,i为循环枚举起始点的x,y值 
		for(int j=1;j<=n-s+1;j++)
		{
			for(int k=1;k<=r;k++)//l,k为循环枚举矩阵的x,y 
				for(int l=1;l<=s;l++)
					sum+=abs(a[l+j-1][k+i-1]-b[l][k]);
			if(sum<min)
			{
				min=sum;
				logx=j;logy=i;
			}
			sum=0;
		}
	
	for(int k=1;k<=r;k++)//l,k为循环枚举矩阵的x,y
		for(int l=1;l<=s;l++)
		{
			printf("%d",a[l+logx-1][k+logy-1]);
			if(l==s)	
				printf("\n");
			else
				printf(" ");
		}
	
	return 0;
}