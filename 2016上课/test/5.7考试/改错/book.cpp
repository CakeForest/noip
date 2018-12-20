#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,k,Page[510],Start[510],End[510];
//二分法
int judge(int mid)
{
	int now=m,left=mid,i=k;//now剩余的书总数 i当前抄书的人的人 
	Start[1]=1;End[k]=m;
	while(now>=1&&i>=1)
	{
		if(left>=Page[now])
			left-=Page[now],now--;
		else
			Start[i]=now+1,End[i-1]=now,i--,left=mid;
	}
	if(now>=1) return -1;//如果已经没人抄书，则返回false
	 return 0;
}

int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	cin>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>Page[i];
	int s=0,e=99999999;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(judge(mid)==-1)
			s=mid+1;
		else if(judge(mid)==0)
			e=mid-1;
	}
	judge(s);
	for(int i=1;i<=k;i++)
		cout<<Start[i]<<" "<<End[i]<<endl;
		
	
	return 0;
}
