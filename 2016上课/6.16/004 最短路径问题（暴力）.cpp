#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct Arc{
	int go,next;
}arc[1000];
struct node{
	int first,x,y;
}P[120];
int arcnum=1,queue[1000],top=0,rear=1,look[120][120];
double queue_data[1000],minn=9999999;
void addarc(int i,int j){
	arc[arcnum].go=j;
	arc[arcnum].next=P[i].first;
	P[i].first=arcnum;
	arcnum++;//i到j有路径 
	arc[arcnum].go=i;
	arc[arcnum].next=P[j].first;
	P[j].first=arcnum;
	arcnum++;//j到i有路径 
}

double dis(int a,int b){
	return sqrt((P[a].x-P[b].x)*(P[a].x-P[b].x)+(P[a].y-P[b].y)*(P[a].y-P[b].y));
}

int main()
{
	freopen("in.txt","r",stdin);
	int n,m,s,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		P[i].x=x;P[i].y=y;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addarc(x,y);
	}
	scanf("%d%d",&s,&t);
	queue[0]=s;
	do{
		int now=queue[top];
		if(now==t) minn=min(minn,queue_data[top]);
		for(int p=P[now].first;p!=0;p=arc[p].next){
			int add=arc[p].go;
			if(look[now][add]==1) continue;
			look[now][add]=1;
			queue[rear]=add;
			queue_data[rear]=queue_data[top]+dis(now,add);
			rear++;
		}
		top++;
	}while(top!=rear);
	printf("%.2f",minn);
	
/*	printf("\n\n\n");
	for(int i=1;i<=n;i++)
	{
		printf("%d:",i);
		for(int p=P[i].first;p!=0;p=arc[p].next){
			printf("%d ",arc[p].go);
		}
		printf("\n");
	}*/
	
	return 0;
}
