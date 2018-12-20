#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
	node()
	{
		x=y=0;
	}
}a[100001];
int mark[200002]={0};
int n,m,sum=0;
bool cmp(node u,node b)
{
	return u.x>b.x;
}
void read()
{
	for(int i=1;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		a[i].x=p;
		a[i].y=i;
	}
}
void run()
{
	sort(a+1,a+1+n,cmp);
	int i=0,j=0;
	while(1)
	{
		i++;
		int p=a[i].y+1,q=a[i].y-1;
		if(p>n)
		{
			p-=n;
		}
		if(q<1)
		{
			q=n;
		}
		if((mark[p]==0)&&(mark[q]==0)&&(j<m))
		{
			mark[a[i].y]=1;
			sum+=a[i].x;
			j++;
		}
		if(i==n)
		{
			break;
		}
	}
	printf("%d",sum);
}
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	scanf("%d%d",&n,&m);
	read();
	if(m>(n/2))
	{
		printf("Error!");
	}
	else
	{
		run();
	}
}
