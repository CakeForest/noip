#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=150000;
int N,P,K,que[MAX],rear,top,exist[MAX];
int first[MAX],nxt[MAX],go[MAX],dis[MAX],quan[MAX],qsum[MAX],arcnum=1;
void addarc(int a,int b,int l){
	nxt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	dis[arcnum]=l;//a到b的距离  
	arcnum++;
	nxt[arcnum]=first[b];
	first[b]=arcnum;
	go[arcnum]=a;
	dis[arcnum]=l;//b到a的距离  
	arcnum++;
}

int Calc(int aim){
	memset(quan,0,sizeof(quan));
	memset(exist,0,sizeof(exist));
	memset(qsum,127,sizeof(qsum));
	for(int i=1;i<arcnum;i++)
		quan[i]=dis[i]>aim;
	que[0]=1;
	rear=1; top=0;
	do{
		int u=que[top],v;
		exist[u]=0;
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			if(qsum[v]>qsum[u]+quan[p]){
				qsum[v]=qsum[u]+quan[p];
				if(!exist[v]){
					que[rear++]=v;
					exist[v]=1;
				}
			}
		}
		top++;
	}while(rear!=top);
	return qsum[N];
}

int BinarySearch(int s,int e){
	int mid,ans;
	while(s<=e){
		mid=(s+e)>>1;
		if(Calc(mid)>=K)
			e=mid-1;
		}else s=mid+1;
	}
	return ans;
}

int main()
{
//	freopen("phoneline.in","r",stdin);
//	freopen("phoneline.out","w",stdout);
	int a,b,l,ans=99999999;
	scanf("%d%d%d",&N,&P,&K);
	for(int i=1;i<=MAX;i++)
		dis[i]=99999999;
	for(int i=1;i<=P;i++){
		scanf("%d%d%d",&a,&b,&l);
		addarc(a,b,l);
	}
	printf("%d",BinarySearch(0,10000000));
	
	
	
	
	return 0;
}
