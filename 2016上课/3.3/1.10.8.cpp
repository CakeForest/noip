#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct peo
{
	int old;
	char id[12];
	int loc;
}pat[120];

int cmp(peo a,peo b)
{
	int t1=a.old,t2=b.old;
	if(t1>=60&&t2>=60)
		if(t1==t2)
			return a.loc<b.loc;
		else
			return t1>t2;
	if((t1>=60)+(t2>=60)==1)
		return t1>=60;
	return a.loc<b.loc;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s %d",pat[i].id,&pat[i].old);
		pat[i].loc=i;
	}
	sort(pat+1,pat+1+n,cmp);
	for(int i=1;i<=n;i++)
		printf("%s\n",pat[i].id);
	return 0;
}
