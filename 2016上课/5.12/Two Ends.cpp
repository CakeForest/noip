#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int map[1200],f[1200][1200],use[1200][1200];
int Game(int s,int e)//��ǰ�������Ϊs�����ұ�Ϊe ������ֵΪ��Ӯ�ķ��� 
{
	if(use[s][e]==1) return f[s][e];
	use[s][e]=1;
	if(s+1==e)//��������ƣ���̰��ѡ�� 
	{
		f[s][e]=max(map[s]-map[e],map[e]-map[s]);
		return f[s][e];
	}
	int left,right,choose;
	choose=map[s];
	if(map[s+1]>=map[e])//����ȡ�� 
		left=choose-map[s+1]+Game(s+2,e);
	else
		left=choose-map[e]+Game(s+1,e-1);
	
	choose=map[e];
	if(map[s]>=map[e-1])//����ȡ�� 
		right=choose-map[s]+Game(s+1,e-1);
	else
		right=choose-map[e-1]+Game(s,e-2);
	
	f[s][e]=max(left,right);
	return f[s][e];
}

void memsets(int n)//��λ 
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			use[i][j]=0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	for(int k=1;k>0;k++)
	{
		int n,sum;
		cin>>n;
		if(n==0) break;
		memsets(n);
		for(int i=1;i<=n;i++)
			cin>>map[i];
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",k,Game(1,n));
	}
	
	return 0;
}
