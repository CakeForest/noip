#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,fruit[50020],len,sum;
bool cmp(int a,int b)
{
	return a<=b;
}

int Get()
{
	int t=fruit[1],now=1,next;
	fruit[1]=fruit[len--];
	while(now*2<=len){////////
		next=now*2;
		if(next<len&&cmp(fruit[next+1],fruit[next])) next++;//������������ӽڵ㣬ѡ�����ȼ��ߵ��ӽڵ� 
		if(cmp(fruit[now],fruit[next])) break;//�����ǰ�ڵ���ӽڵ����ȼ��ߣ����˳� 
		swap(fruit[now],fruit[next]);//���򽻻��ӽڵ�͸��׽ڵ� 
		now=next;
	}
	return t;
}

int Put(int p)
{
	int now=++len,nxt;
	fruit[len]=p;
	while(now>1)
	{
		nxt=now/2;
		if(cmp(fruit[now],fruit[nxt]))
			swap(fruit[now],fruit[nxt]),now=nxt;
		else break;
	}
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		Put(t);
	}
	for(int i=1;i<=n-1;i++)//n-1�β��� 
	{
		int t=Get()+Get();
		sum+=t;
		Put(t);
	}
	printf("%d",sum);
	
	
	return 0;
}
