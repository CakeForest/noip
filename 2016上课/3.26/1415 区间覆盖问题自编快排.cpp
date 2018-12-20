#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct node{
	int s,e;
}line[1000020];
int n,left,right;
int cmp(node l1,node l2)
{
	if(l1.s!=l2.s)
		return l1.s<l2.s;//如果起点不同则按起点排序 
}

void Swap(int l,int r)//打乱函数 
{
	node change=line[l];
	int RandNum=rand()%(r-l)+l;
	line[l]=line[RandNum];
	line[RandNum]=change;
}

void QuickSort(int l,int r)//快速排序
{
	if(l>=r)
		return;
	int i=l,j=r;
	Swap(l,r);
	node key=line[l];
	while(i<j)
	{
		while(i<j&&line[j].s>key.s) j--;
		line[i]=line[j];
		while(i<j&&line[i].s<key.s) i++;
		line[j]=line[i];
	}
	line[i]=key;
	QuickSort(l,i-1);
	QuickSort(i+1,r);
}

void Test()//测试 
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
	scanf("%d %d",&left,&right);
	QuickSort(1,n);
	
/*	Test();
	return 0;*/
	int i=1,sum=0,flag=0;
	while(i<=n&&flag==0)
	{
		int farest=-1;//记录能达到的最远位置 
		while(line[i].s<=left)
		{
			if(line[i].e>farest)
				farest=line[i].e;
			i++;
		}
		if(farest==-1)
			goto end;
		left=farest;
		sum++;
		if(left>=right)
			flag=1;
	}
	if(flag==1)
		printf("%d",sum);
	else
		end:printf("no solution!");

	
	return 0;
}
