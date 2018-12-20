#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct node{
	int s,e;
}line[1000020];
int n;
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
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&line[i].s,&line[i].e);
	QuickSort(1,n);
	
	//Test();	
	int now=line[1].e,sum=1,i=2;
	while(i<=n)
	{
		if(!(line[i].s<=now&&line[i].e>=now))
			sum++,now=line[i].e;
		i++;
	}
	printf("%d",sum);
	
	return 0;
}
