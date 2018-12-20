#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=9999999;
int pp[100],enter[100],exitt[100];
int first[100],nxt[300],go[300],val[300],arcnum;
int que[10000],top,rear,f[100][100],step[100],phone[100];//f��ʾ��j��ʱ������k���绰����s�������ѵĴ��� 
void prin(int a,int b,int c){
	printf("%d %d %d\n",a,b,c);
}

void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	val[arcnum]=c;
	
//	prin(a,b,c);
}

int main(){
	freopen("CheapestRoute.in","r",stdin);
	freopen("CheapestRoute.out","w",stdout);
	int z,n,m,k;
	scanf("%d",&z);
	while(z--){
		memset(first,0,sizeof(first));
		memset(step,0,sizeof(step));
		memset(phone,0,sizeof(phone));
		top=rear=arcnum=0;
		for(int i=0;i<=60;i++)
			for(int j=0;j<=60;j++)
				f[i][j]=INF;
		
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&pp[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d",&enter[i]),enter[i]++;
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d",&exitt[i]),exitt[i]++;
		scanf("%d",&k);
		
		for(int i=1;i<=n-1;i++)//���ڵ�Ԫ��·������ 
			if(pp[i]>=0&&pp[i+1]>=0)
				addarc(i,i+1,0);
		for(int i=1;i<=n;i++)//�绰·������ 
			if(pp[enter[i]]>=0&&pp[exitt[i]]>=0)
				addarc(enter[i],exitt[i],1);
		
		que[rear++]=1; f[1][0]=0;
		do{
			int u=que[top++],v;
			for(int p=first[u];p!=0;p=nxt[p]){
				v=go[p];
				if(val[p]==1){//����ǵ绰 
					if(f[v][phone[v]]>f[u][phone[u]]+phone[u]+k){
						phone[v]++;
						f[v][phone[v]]=f[u][phone[u]]+phone[u]+k;
						step[v]=step[u]+1;
						que[rear++]=v;
					}
				}else{//������ǵ绰  
					if(f[v][phone[v]]>f[u][phone[u]]+pp[v]){
						f[v][phone[v]]=f[u][phone[u]]+pp[v];
						step[v]=step[u]+1;
						que[rear++]=v;
					}	
				}
			}
		}while(top!=rear);
		if(f[n][phone[n]]!=INF) printf("%d %d\n",f[n][phone[n]],step[n]);
		else printf("-1 -1\n");
	}
	
	
	
	
	return 0;
}
