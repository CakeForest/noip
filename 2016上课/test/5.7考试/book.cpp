#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,k,Page[510],f[510][510],cut[510],next[510];
//��������� 
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
	//f[i][j]��ʾ�ӵ�i���鳭����j����Ҫ��ʱ�� 
	for(int len=m-1;len>=k;len--)//lenΪ��ǰ������� 
	{
		int minn=99999999,log_last,log_now,now=next[0],last=0;
		do{
			int t=f[cut[last]+1][cut[now]]+f[cut[now]+1][cut[next[now]]];
			if(t<=minn)//������ǰ������ٳ�д 
				minn=t,log_last=last,log_now=now;
			last=now;
			now=next[now];
		}while(next[now]!=-1);
		f[cut[log_last]+1][cut[next[log_now]]]=minn;//�����ŵ������˵Ĺ������ϲ� 
		next[log_last]=next[log_now];//ɾ���ѻ���λ�� 
	}
	
	for(int now=0;next[now]!=-1;now=next[now])
		cout<<cut[now]+1<<" "<<cut[next[now]]<<endl;
	
	return 0;
}
