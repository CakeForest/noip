#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

bool cmp(int x,int y)
{
	if(x%2==0&&y%2==0)
		return x<y;
	else if(x%2==1&&y%2==1)
		return x>y;
	else
		return x%2==1;
}

int main()
{
	int a[12];
	for(int i=1;i<=10;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+11,cmp);
	
	for(int i=1;i<=10;i++)
	{
		printf("%d",a[i]);
		if(i!=10)
			printf(" ");
	}
	
	return 0;
}
