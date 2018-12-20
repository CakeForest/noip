#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
struct circle
{
	double x;
	double r;
}a[8];
double h,x0;
int judge(double mid)//判断当前增加的半径是否符合 
{//如果某个彩虹半径太大，也可以符合条件 
	for(int i=0;i<=6;i++)
	{
		double dis1=sqrt((a[i].r+mid)*(a[i].r+mid)-h*h);
		double dis2=sqrt((a[i+1].r+mid)*(a[i+1].r+mid)-h*h);
		if(dis1+dis2<a[i+1].x-a[i].x)
			return -1; 
		else if(fabs(dis1+dis2-a[i+1].x-a[i].x)<0.00000001)
			return 0; 
	}
	return 1;
}

bool cmp(circle x,circle y)
{
	return x.x<y.x;
}

void pri(double mid)
{
//	mid+=0.005;//***************
	printf("%.2f",mid);
}

int main()
{
	freopen("rainbow.in","r",stdin);
	freopen("rainbow.out","w",stdout);
	scanf("%lf %lf",&h,&x0);
	a[0].x=0;
	a[0].r=0;
	for(int i=1;i<=7;i++)
		scanf("%lf %lf",&a[i].x,&a[i].r);
	sort(a+1,a+1+7,cmp);
	
	double s,e;
	s=0;
	e=9999999;
	while(s<=e)
	{
		double mid=(s+e)/2;
		int j=judge(mid);
		if(j==0)
		{
			pri(mid);
			return 0;
		}
		else if(j==-1)
			s=mid;
		else if(j==1)
			e=mid;
		if(fabs(e-s)<=0.01)
		{
			pri((e+s)/2);
			return 0;
		}
	}
	
	
	fclose(stdout);
	return 0;
}
