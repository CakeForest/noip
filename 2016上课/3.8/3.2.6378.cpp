#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAXN=200020;
int data[MAXN],next[MAXN],head;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,k;
	scanf("%d",&n);
	
	int i;
	next[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
		next[i]=i+1;
	}
	next[i-1]=-1;
	
	int p,pre=0;
	scanf("%d",&k);
	for(p=1;next[p]!=-1;p=next[p])
	{
		if(data[p]==k)
			next[pre]=next[p];
		else
			pre=p;
	}
	
	for(p=next[0];next[p]!=-1;p=next[p])
		printf("%d ",data[p]);

}
