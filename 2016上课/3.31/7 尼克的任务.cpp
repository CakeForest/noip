#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE=10020;
struct node{
	int p,t;
}job[MAXSIZE];
int n,k,ans[MAXSIZE],now;
// 逆向动归，求出每分钟的最优解 
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d %d",&job[i].p,&job[i].t);

	now=k;
	for(int i=n;i>=1;i--)
	{
		if(i!=job[now].p)
			ans[i]=ans[i+1]+1;
		else
		{
			ans[i]=ans[i+job[now--].t];
			while(now>=1&&job[now].p==job[now+1].p)
				ans[i]=max(ans[i],ans[i+job[now--].t]);
		}
	}
	
	
	/*for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n\n\n");*/
	
	printf("%d",ans[1]);
	
	return 0;
}
