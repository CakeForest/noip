#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXSIZE=150000;
long long ans[MAXSIZE]={0};
long long two[MAXSIZE],three[MAXSIZE],five[MAXSIZE];
int rear2,rear3,rear5,top2,top3,top5;


long long judge()//输出最小值 
{
	long long a=two[top2],b=three[top3],c=five[top5];
	if(a<=b&&a<=c)
	{
		top2++;
		return a;
	}
	if(b<=a&&b<=c)
	{
		top3++;
		return b;
	}
	else
	{
		top5++;
		return c;
	}
}

int main()
{
	freopen("chou.in","r",stdin);
	freopen("chou.out","w",stdout);
	ans[1]=1; 
	rear2=1; rear3=1; rear5=1;
	top2=0; top3=0; top5=0;
	two[0]=2; three[0]=3; five[0]=5;//初始化 
	
	

	int n,i=1;
	long long pre=1;
	scanf("%d",&n);
	while(i<=n+1)
	{
		long long next=judge();
		if(next==pre)
  			continue;//重复，找下一个 
  		else
  		{
  			pre=next;
  			ans[++i]=next;
  			two[rear2++]=next*2;
  			three[rear3++]=next*3;
  			five[rear5++]=next*5;
  		}
  		
	}
	printf("%lld",ans[n]);
	
	return 0;
}
