#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n;
	double a[400];
	scanf("%d",&n);
	double max,min;
	double zong=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		if(i==1)
		{
			max=a[i];
			min=a[i];
		}
		else
		{
			max=a[i]>max?a[i]:max;
			min=a[i]<min?a[i]:min;
		}
		zong+=a[i];
	}
	double ping,wucha=0;
	ping=(zong-max-min)/(n-2);
	int mx=0,mm=0;
	for(int i=1;i<=n;i++)
	{
		if(mx==0&&a[i]==max)
			mx++;
		else 
			wucha=wucha>(a[i]-ping)?wucha:(a[i]-ping);
		if(mm==0&&a[i]==min)
			mm++;
		else 
			wucha=wucha>(ping-a[i])?wucha:(ping-a[i]);
	}
	printf("%.2f %.2f",ping,wucha);
	
	
	return 0;
}