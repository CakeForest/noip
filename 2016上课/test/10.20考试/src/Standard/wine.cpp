/*
   ��̬�滮����С��������״̬ѹ��
   1.�ҳ����о�����Ϊ0�ļ��ϡ�
     ���ü��ϵĵ�����ͨ�ģ���ô����ü��ϵ���С����������������ֵ���Ǹü��Ͼ���ת��������С����
   2.��ÿһ��Ϊ0�ļ��Ͽ�����һ����Ʒ�����ñ�������������Ž⡣
   
   ���������ǣ�
   �ö�������ѹ��״̬��1����ڵ��ڼ����У�0�����ڡ�
   ��������s�Ķ�������ʽΪ100111������0,1,2,5�Žڵ���s��ʾ�ļ����С�
   
   ��Ŀ�����n(n<=16)���ڵ㣬���s�ķ�Χ��0��(2^n)-1 Ҳ����(1<<n)-1 
   ������Sum[s]����¼����s�а����Ľڵ�ľ���֮�͡� 
   
   ����ÿһ��������Ϊ0�ļ���x(Sum[x]==0)�����ܵõ�һ����С��������������Cost[x]��¼�¸��������Ĵ���
   
   f[i]��¼ƽ�⼯��i�еĽڵ�ľ���ֵ��������С���� 
   ���ڼ���i��j,������Sum[i]==0��Sum[j]==0
   ��ô��f[i|j]=min(f[i|j],f[i]+Cost[j]); 
   i|j��ʾ����i�뼯��j�ϲ�֮��ļ��� 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=1000000000;
struct node{int x,y,z;}Edge[150];
int n,m,A[17],Father[17],Sum[1<<17],Cost[1<<17],f[1<<17];

bool cmp(node a,node b){ return a.z<b.z;}

int GetFather(int x)
{
	if(x!=Father[x])Father[x]=GetFather(Father[x]);
	return Father[x];
}

int Kruskal(int s)  //����״̬s�а����ĵ㣬���ɵ���С������ 
{
	int i,MinCost=0,Cnt=0,tot=0,fx,fy;
	for(i=0;i<n;i++)
	{
	  Father[i]=i;                //��ʼ�����鼯 
	  if((s>>i)&1)tot++;          //totͳ��s״̬�а����Ľڵ��� 
    }

	for(i=1;i<=m;i++)
	  if(((s>>Edge[i].x)&1)&&((s>>Edge[i].y)&1))//�ж�״̬s���Ƿ�����˱�i�������˵� 
	  {
	  	  fx=GetFather(Edge[i].x);
		  fy=GetFather(Edge[i].y);
		  if(fx!=fy)
		  {
		  	  Father[fx]=fy;
		  	  Cnt++;               //Cnt��¼�������нڵ�ĸ���
			  MinCost+=Edge[i].z; 
		  }
	  }
	if(Cnt+1!=tot) return inf;   //��Cnt+1<tot�����нڵ�û���뵽���������ü��ϲ���ͨ 
	else return MinCost; 
}

int main()
{
	freopen("wine.in","r",stdin);
    freopen("wine.out","w",stdout);
	int i,j,Tot;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",&A[i]);
	for(i=1;i<=m;i++)scanf("%d%d%d",&Edge[i].x,&Edge[i].y,&Edge[i].z);
	sort(Edge+1,Edge+m+1,cmp);
	
	Tot=(1<<n)-1;         //�ܵ�״̬�� 
	for(i=0;i<=Tot;i++)   //����ÿһ��״̬��ʾ�ļ��ϣ���¼���нڵ�ľ����ܺ� 
	  for(j=0;j<n;j++)
	    if((i>>j)&1)Sum[i]+=A[j]; 
	    
	for(i=0;i<=Tot;i++)
	  if(Sum[i]==0)Cost[i]=Kruskal(i);  //��i��ʾ�ļ����У��ڵ������Ϊ0����������С������ 
	  else Cost[i]=inf;
    
	for(i=1;i<=Tot;i++)f[i]=inf;
	f[0]=0;
	
	for(i=0;i<=Tot;i++)
	{
		if(Sum[i]!=0)continue;
		for(j=1;j<=Tot;j++)
		{
			if(Sum[j]!=0)continue;
			f[i|j]=min(f[i|j],f[i]+Cost[j]);
	    }
	} 

	if(f[Tot]==inf)printf("Impossible\n");else printf("%d\n",f[Tot]); 
	return 0;
}
