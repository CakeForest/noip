#include<stdio.h>
using namespace std;
const int MAXSIZE=100000;
int s1[MAXSIZE],s2[MAXSIZE],ans[MAXSIZE];
int top1=0,top2=0,rear1=0,rear2=0;
int main()
{
	int now=1,j,n,last=1;
	scanf("%d",&n);
	ans[now]=1;
	if(n>=1) printf("1 ");
	for(int i=2;i<=n;i++)
	{
		do{
			j=ans[now];
			s1[rear1++]=j*2+1;
			s2[rear2++]=j*3+1;
			ans[++now]=s1[top1]<s2[top2]?s1[top1++]:s2[top2++];
		}while(last==ans[now]);
		last=ans[now];
		printf("%d ",ans[now]);
		
	}
		
	
	return 0;
}
