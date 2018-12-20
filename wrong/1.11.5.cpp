#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int p,f;
double pai[10020];//派的半径  高为1  

int judge(double mid)
{
	double left=pai[1];
	int now=1;
	for(int i=0;i<=f;i++)//f+1个人 
	{
		while(left<mid)
		{
			if(now+1<=p)
				left=pai[++now];
			else
				return -1;
		}
		left-=mid;
	}
	return 1;
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d %d",&p,&f);
	for(int i=1;i<=p;i++)
		scanf("%lf",&pai[i]);
		
	double s=0,e=999999,mid;
	while(e-s>=1e-5)
	{
		mid=(s+e)/2;
		if(judge(mid)==1)
			s=mid+0.00001;
		else
			e=mid-0.00001;
	}
	printf("%.3lf",mid);
	
	return 0;
}
