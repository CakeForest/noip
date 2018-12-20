#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXSIZE=1000020;
struct node{
	int s,e;
}line[MAXSIZE];
int n,ans[MAXSIZE];
void Swap(int l,int r)
{
	node change=line[l];
	int RandNum=rand()%(r-l)+l;
	line[l]=line[RandNum];
	line[RandNum]=change;
}

void QuickSort(int l,int r)
{
	if(l>=r)
		return;
	int i=l,j=r;
	Swap(l,r);
	node key=line[l];
	while(i<j)
	{
		while(i<j&&line[j].e>=key.e) j--;
		line[i]=line[j];
		while(i<j&&line[i].e<=key.e) i++;
		line[j]=line[i];
	}
	line[i]=key;
	QuickSort(l,i-1);
	QuickSort(i+1,r);
}

void Test()
{
	for(int i=1;i<=n;i++)
		printf("%d %d\n",line[i].s,line[i].e);
	printf("\n\n\n");
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&line[i].s,&line[i].e);
	QuickSort(1,n);
	
	//Test();	
	int now=0,sum=0,log=1;
	for(int i=1;i<=n;i++)
	{
		if(line[i].s>=now)
			now=line[i].e,sum++,ans[log++]=i;
	}
	printf("%d\n",sum);
/*	for(int i=1;i<log;i++)
		printf("%d ",ans[i]);*/
	return 0;
}
