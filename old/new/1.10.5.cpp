#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct stu
{
	int id,score;
}people[6000];

int cmp(stu a,stu b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	return a.id<b.id;
}

int main()
{
	int n,m,aimid,sum=0;
	scanf("%d %d",&n,&m);
	m*=1.5;
	for(int i=1;i<=n;i++)
		scanf("%d %d",&people[i].id,&people[i].score);
	sort(people+1,people+1+n,cmp);
	aimid=m;
	int log=people[m].score;
	sum=m;
	while(people[aimid+1].score==log&&aimid<=n)
	{
		sum++;
		aimid++;
	}
	
	printf("%d %d\n",people[m].score,sum);
	for(int i=1;i<=aimid;i++)
	{
		printf("%d %d\n",people[i].id,people[i].score);
	}
	return 0;
}
