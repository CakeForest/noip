#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int m,n,r,s;//m,rΪx   r,sΪy 
	int a[120][120],b[120][120];
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j][i]);
	scanf("%d %d",&r,&s);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=s;j++)
			scanf("%d",&b[j][i]);//��ȡ���� 
	
	int min=429496729; int logx,logy;
	int sum=0;//ö�����п���
	for(int i=1;i<=m-r+1;i++) //j,iΪѭ��ö����ʼ���x,yֵ 
		for(int j=1;j<=n-s+1;j++)
		{
			for(int k=1;k<=r;k++)//l,kΪѭ��ö�پ����x,y 
				for(int l=1;l<=s;l++)
					sum+=abs(a[l+j-1][k+i-1]-b[l][k]);
			if(sum<min)
			{
				min=sum;
				logx=j;logy=i;
			}
			sum=0;
		}
	
	for(int k=1;k<=r;k++)//l,kΪѭ��ö�پ����x,y
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