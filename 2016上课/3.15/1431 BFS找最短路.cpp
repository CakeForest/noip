#include<stdio.h>
using namespace std;
int use[100]={0},h;
int father[100]={0},queue[100]={0},rear,top,map[30][30]={0};
int start,end,n;

void pri(int x)
{
	int ans[31],j=30;
	int now;
	for(now=x;father[now]!=-1;now=father[now])
		ans[j--]=queue[now];
	ans[j]=queue[now];
//	printf("%c->",'A'+start-1);
	for(int i=j;i<=30;i++)
		if(i!=30)
			printf("%c->",'A'+ans[i]-1);
		else
			printf("%c",'A'+ans[i]-1);
	
}

int main()
{
	int x,y;
	scanf("%d %d %d",&start,&end,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		map[x][y]=1;
	}
	rear=1;top=0;
	queue[top]=start;//��ʼ��ΪA
	use[start]=1;father[0]=-1;
	
	do{
		h=queue[top];//�ӶѶ�ȡ��Ԫ�� 
		for(int i=1;i<=30;i++)//Ѱ����һ���ڵ� 
			if(map[h][i]==1)
			{
				if(i==end)//������յ㣬��� 
				{
					father[rear]=top;
					queue[rear]=end;
					pri(rear);
					return 0;
				}
				if(use[i]==0)//���δ���߹�����ջ 
				{
					use[i]=1;
					father[rear]=top;
					queue[rear++]=i;
				}
			}
		top++;
	}while(top!=rear);
}
