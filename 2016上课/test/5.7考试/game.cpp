#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long N,M,T=0,k=0;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>N>>M;
	T=N-1;//����ΪN-1��������N 
	long long sum=1;//�˴��ؼ� ��Ϸ��ʼʱ�����Ѿ�����1�� 
	for(int i=1;i<=M;i++)
	{
		long long c;
		cin>>c;sum+=c;
	}
	long long ans=sum%T;//ȡģ
	long long times=(sum-1)/T;
	if(times%2==0)
		printf("%lld",ans==0?T:ans);
	else
		printf("%lld",ans==0?N-T+1:N+1-ans);
	
	return 0;
}
