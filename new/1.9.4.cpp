#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	char name[120][30];
	int score1,score2,essay;
	char ganbu,xibu;
	
	int sum=0;
	int max=-1,log=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s %d %d %c %c %d",name[i],&score1,&score2,&ganbu,&xibu,&essay);
		int now=0;
		now+=(score1>80&&essay>=1)?8000:0;
		now+=(score1>85&&score2>80)?4000:0;
		now+=score1>90?2000:0;
		now+=(score1>85&&xibu=='Y')?1000:0;
		now+=(score2>80&&ganbu=='Y')?850:0;
		if(now>max)
		{
			max=now;
			log=i;
		}
		sum+=now;
	}
	printf("%s\n%d\n%d",name[log],max,sum);
	
	return 0;
}