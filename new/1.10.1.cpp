#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct stu
{
	char a[10];
	double b;
};
stu p[110];

bool cmp(stu a,stu b)
{
	if(a.b>b.b)
		return true;
	return false;
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%s %lf",p[i].a,&p[i].b);
	
	sort(p+1,p+1+n,cmp);
	printf("%s %g",p[k].a,p[k].b);

	
	return 0;
}
