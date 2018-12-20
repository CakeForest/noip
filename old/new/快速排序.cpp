#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

void dsort(int left,int right);
int num[100000];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	dsort(1,n);//自编快排
//	sort(num+1,num+n+1);//函数快排 
	for(int i=1;i<=n;i++)
		printf("%d ",num[i]);
}

void dsort(int left,int right)
{
	int i,j;
	double x,y;
	i=left;j=right;
	x=num[(left+right)/2];
	do{
		while(num[i]<x) i++;
		while(num[j]>x) j--;
		y=num[i]; num[i]=num[j]; num[j]=y;
		i++;j--;
	}while(i<=j);
	if(left<j) dsort(left,j);
	if(i<right) dsort(i,right);
}
