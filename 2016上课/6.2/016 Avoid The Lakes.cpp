#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
}que[10020],P[10020];
int dis,visit[120][120],map[120][120],top,rear,maxx=-1;
int n,m,k,num;
bool exist(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m&&visit[x][y]==0&&map[x][y]==1)
		return 1;//�ж�ĳ���Ƿ����ˮ��δ������ 
	return 0;
}

void add(int x,int y){
	que[rear].x=x; que[rear].y=y;//���õ������ 
	visit[x][y]=1;//�������Ϳ�� 
	rear++;dis++;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int a,b;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&a,&b);
		num++;
		P[i].x=a;P[i].y=b;
		map[a][b]=1;//��¼��������ˮ 
	}
	for(int i=1;i<=num;i++)
	{
		if(exist(P[i].x,P[i].y)==0) continue; 
		top=0;rear=0;dis=0;add(P[i].x,P[i].y);//��ʼ�� ����ʼ��
		do{
			a=que[top].x;b=que[top].y;//��ǰ��
			if(exist(a,b+1)) add(a,b+1);
			if(exist(a,b-1)) add(a,b-1); 
			if(exist(a+1,b)) add(a+1,b);
			if(exist(a-1,b)) add(a-1,b);
			top++;
		}while(top!=rear);
		maxx=max(maxx,dis);
	}
	printf("%d",maxx);
	
	return 0;
}
