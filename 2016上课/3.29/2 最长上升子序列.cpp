#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=1000000;
int n,a[MAXSIZE],ans[MAXSIZE];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),ans[i]=1;
	a[0]=0; ans[0]=0;
	for(int i=1;i<=n;i++)
	{
		int now=a[i];
		for(int j=i-1;j>=0;j--)
			if(now>a[j])
				ans[i]=ans[i]>ans[j]+1?ans[i]:(ans[j]+1);
	}
	int max=0;
	for(int i=1;i<=n;i++)
		if(ans[i]>max)
			max=ans[i];
	if(n==0)
		printf("0");
	else
		printf("%d",max);
	
	return 0;
}
