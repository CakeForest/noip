#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[30000];

bool cmp(int x,int y)
{
	int t=(x%2==1)+(y%2==1);
	if(t==2||t==0)
		return x<y;
	else
		return x%2==1;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	int i=2;
	printf("%d",a[1]);
	while(a[i]%2==1)
	{
		printf(",%d",a[i]);
		i++;
	}
	return 0;
}
