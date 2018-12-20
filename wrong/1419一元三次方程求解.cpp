#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double ans,a,b,c,d;
void pri(int sum)
{
	printf("%.2lf",ans+0.005);
	if(sum!=3)
		printf(" ");
}

double work(double x,double y)//now:现在精确小数点位数 
{
	if(fabs(x-y)<0.01)
		return (x+y)/2;
	double m=(x+y)/2,j;
	
//	printf("-------x:%lf y:%lf m:%lf\n",x,y,m);
	
	j=a*m*m*m+b*m*m+c*m+d;
	if(fabs(j)<=0.00001)
		return m*1.0;
	else if(j>0)
		return work(m,y);
	else if(j<0)
		return work(x,m);
}

int main()
{
	freopen("in.txt","r",stdin);
	double y[300];
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	for(int i=-100;i<=100;i++)
		y[i+100]=a*i*i*i+b*i*i+c*i+d;
	int sum=0;
	for(int i=-100;i<=100;i++)
	{
		if(fabs(y[i+100])<=0.0000001)
		{
			sum++;
			ans=i*1.0;
			pri(sum);
			if(sum==3)
				break;
		}
		if(y[i+100]*y[i+1+100]<0)
		{
			sum++;
			if(y[i+100]>0)
				ans=work(i,i+1);
			else
				ans=work(i+1,i);
			pri(sum);
			if(sum==3)
				break;
		}
	}

	
	return 0;
}
