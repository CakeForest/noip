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

int judge(double mid)//�жϵ�ǰ���ӵİ뾶�Ƿ��ʹ��ͨ�� 
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
		scanf("%lf %lf",&rainbow[i].x,&rainbow[i].r);//�������ݣ�����ŵ��ṹ���� 
	sort(rainbow,rainbow+7,cmp);//��������
	
	double s,e;
	s=0;
	e=9999999;
	while(e-s>1e-5)//�Ծ���Ϊ�߽�ֵ�����Կ��ðѾ������õô�һ�� 
	{
		double mid=(s+e)/2;
		if(judge(mid))
			e=mid;//����
		else
			s=mid;//С�� 
	}
	printf("%.2lf",mid);//����������� 
	
	fclose(stdout);
	return 0;
}
