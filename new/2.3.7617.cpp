#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	int n,a[100000],k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=k;i++)
		printf("%d\n",a[i]);
	
	return 0;
}
