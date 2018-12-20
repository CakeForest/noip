#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct stu
{
	int c,m,e,sum,id;
}t[500];

bool cmp(stu x,stu y)
{
	if(x.sum>y.sum||x.sum<y.sum)
		return x.sum>y.sum;
	if(x.c>y.c||x.c<y.c)
		return x.c>y.c;
	return x.id<y.id;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&t[i].c,&t[i].m,&t[i].e);
		t[i].id=i;
		t[i].sum=t[i].c+t[i].m+t[i].e;
	}

	sort(t+1,t+n+1,cmp);
	
	for(int i=1;i<=5;i++)
		printf("%d %d\n",t[i].id,t[i].sum);
	
	
	return 0;
}
