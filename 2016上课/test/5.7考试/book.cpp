#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,k,Page[510],f[510][510],cut[510],next[510];
//动归加链表 
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	cin>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>Page[i];f[i][i]=Page[i];
		if(i!=m)
			cut[i]=i;
		next[i]=i+1;
	}
	cut[0]=0;next[0]=1;
	cut[m]=m;next[m]=-1;
	//f[i][j]表示从第i本书抄到第j本书要的时间 
	for(int len=m-1;len>=k;len--)//len为当前抄书的人 
	{
		int minn=99999999,log_last,log_now,now=next[0],last=0;
		do{
			int t=f[cut[last]+1][cut[now]]+f[cut[now]+1][cut[next[now]]];
			if(t<=minn)//尽量让前面的人少抄写 
				minn=t,log_last=last,log_now=now;
			last=now;
			now=next[now];
		}while(next[now]!=-1);
		f[cut[log_last]+1][cut[next[log_now]]]=minn;//将最优的两个人的工作量合并 
		next[log_last]=next[log_now];//删除已划分位置 
	}
	
	for(int now=0;next[now]!=-1;now=next[now])
		cout<<cut[now]+1<<" "<<cut[next[now]]<<endl;
	
	return 0;
}
