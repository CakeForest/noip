#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);
	int num[10]={0};
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int old;
		scanf("%d",&old);
		if(old>=0&&old<=18)
			num[0]++;
		if(old>=19&&old<=35)
			num[1]++;
		if(old>=36&&old<=60)
			num[2]++;
		if(old>=61)
			num[3]++;
		sum++;
	}
	printf("%.2lf%%\n",100.0*num[0]/sum);
	printf("%.2lf%%\n",100.0*num[1]/sum);
	printf("%.2lf%%\n",100.0*num[2]/sum);
	printf("%.2lf%%",100.0*num[3]/sum);
	return 0;
}