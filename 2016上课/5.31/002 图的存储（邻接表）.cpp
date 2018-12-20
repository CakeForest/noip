#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct arc{
	int go,next; 
}Arc[20020];
struct node{
	int first;
	char data[35];
}P[20020];
int arcnum=0,out[20020];
bool cmp(int a,int b)
{
	return a<b;
}

void Addarc(int a,int b)
{
	Arc[arcnum].go=b;
	Arc[arcnum].next=P[a].first;
	P[a].first=arcnum;
	arcnum++;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,k,a,b;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
		scanf("%s",P[i].data),P[i].first=-1;//读入每个点的数据 
	for(int i=1;i<=m;i++)
		scanf("%d %d",&a,&b),Addarc(a,b);//建立a到b的边 
	for(int i=1;i<=k;i++)
	{
 		scanf("%d",&a);
		if(P[a].first==-1)//没有临接点 
			printf("0");
		else{
			int p=P[a].first,sum=0;
			do{
				sum++;
				out[sum]=Arc[p].go;//依次存储该点的临接点 
				p=Arc[p].next;
			}while(p!=-1);
			sort(out+1,out+1+sum,cmp);
			for(int i=1;i<=sum;i++)
				printf("%s ",P[out[i]].data);
		}
		printf("\n");
	}
	
	return 0;
}
