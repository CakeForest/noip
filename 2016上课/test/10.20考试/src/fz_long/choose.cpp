#include<cstdio>
#include<algorithm>
using namespace std;
int l[5010],n,m,ans1,ans2;
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	scanf("%d%d",&n,&m);
	int k=n/2;
	if(k<m)
	{
		printf("Error!\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&l[i]);
	if(k==m)
	{
		for(int i=1;i<=n;i+=2)
			ans1+=l[i];
		for(int i=2;i<=n;i+=2)
			ans2+=l[i];
		if(ans1>ans2)
			printf("%d\n",ans1);
		else
			printf("%d\n",ans2);
		return 0;
	}
	return 0;
}
