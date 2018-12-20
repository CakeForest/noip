#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct stu
{
	char name[10];
	int score;
}student[30];

bool cmp(stu a,stu b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return strcmp(a.name,b.name)<0?true:false;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s %d",student[i].name,&student[i].score);
	sort(student+1,student+1+n,cmp);
	
	for(int i=1;i<=n;i++)
		printf("%s %d\n",student[i].name,student[i].score);

	
	return 0;
}
