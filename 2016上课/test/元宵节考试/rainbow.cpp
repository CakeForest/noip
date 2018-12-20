#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
struct point
{
	double r;
	double x;
}rainbow[7];
double h,x0;

int judge(double mid)//判断当前增加的半径是否可使人通过 
{
	double t[8];
	for(int i=0;i<=6;i++)
	{
		t[i]=rainbow[i].x-
		
	}
	
}
bool cmp(point a,point b)
{
	return a.x<b.x;
}

int main()
{
	freopen("rainbow.in","r",stdin);
	freopen("rainbow.out","w",stdout);
	scanf("%lf %lf",&h,&x0);
	for(int i=0;i<=6;i++)
		scanf("%lf %lf",&rainbow[i].x,&rainbow[i].r);//读入数据，并存放到结构体中 
	sort(rainbow,rainbow+7,cmp);//排序数据
	
	double s,e;
	s=0;
	e=9999999;
	while(e-s>1e-5)//以精度为边界值，可以开得把精度设置得大一点 
	{
		double mid=(s+e)/2;
		if(judge(mid))
			e=mid;//大了
		else
			s=mid;//小了 
	}
	printf("%.2lf",mid);//四舍五入输出 
	
	fclose(stdout);
	return 0;
}
