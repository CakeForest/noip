#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int a[500000];
	int i,n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	i=n;
	while(m!=1)
	{
		m--;
		ans+=a[i];
		i=i-2;
	}
	if(m>n/2) printf("Error");
	  else printf("%d",ans);
	return 0;   
}
