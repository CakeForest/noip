#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	int a[10001][5];
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d %d %d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
	scanf("%d %d",&x,&y);
	
	int log=-1;
	for(int i=1;i<=n;i++)
		if(x<=a[i][1]+a[i][3]&&x>=a[i][1]&&y<=a[i][2]+a[i][4]&&y>=a[i][2])
			log=i;
	
	printf("%d",log);
	
	return 0;
}