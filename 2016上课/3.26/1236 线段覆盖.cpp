#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int s,e;
}line[1000020];
int n;
int cmp(node x,node y)
{
	return x.e<y.e;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&line[i].s,&line[i].e);
	sort(line+1,line+n+1,cmp);
	int now=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(line[i].s>=now)
			now=line[i].e,sum++;
	}
	printf("%d",sum);
	
	return 0;
}
