#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=10020;
int n,a[MAXSIZE],b[MAXSIZE];//a田忌 b国王 
int cmp(int x,int y)
{
	return x>y;
}
/*贪心:如果一定赢不了，用最小的马去和最大的马比
	否则 用刚好比国王马大的马比*/
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);	
	sort(a+1,a+1+n,cmp);//田忌从大到小排序 
	sort(b+1,b+1+n,cmp);//国王从大到小排序 
	int s1=1,e1=n;
	int s2=1,e2=n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[s1]>b[s2])//最大的马和最大的马比 
			sum++,s1++,s2++;
		else if(a[s1]<b[s2])//最大的马赢不了，用小的充数 
			sum--,e1--,s2++;
		else if(a[e1]>b[e2])//两马打平，比最小的马，如果最小的马可以赢就赢 
			sum++,e1--,e2--;
		else //不能赢就用最小的马充数 
			sum+=a[e1]<b[s2]?-1:0,e1--,s2++;//重要 
	}
	printf("%d",sum*200);
	
	return 0;
}
