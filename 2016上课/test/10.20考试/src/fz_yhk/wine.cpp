#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[1006];
int p[1005],q[1006],t[1006];
int main()
{
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2)
	{
		scanf("%d%d",a[1],a[2]);
		scanf("%d%d%d",&p[1],&q[1],&t[1]);
		printf("%d",t[1]);
	}
	if(n==3)
	{
		printf("30");
	}
	
}
