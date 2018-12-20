#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int first[300],nxt[40200],go[40200],arcnum;
int rd[300],stack[40200],ans[300],heap[10000],len;
void addarc(int a,int b){
	nxt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum++]=b;
}

bool cmp(int a,int b){
	return a<b;
}

int Get(){
	int t=heap[1],now=1,next;
	heap[1]=heap[len--];
	while(now*2<=len){
		next=now*2;
		if(next<len&&cmp(heap[next+1],heap[next])) next++;
		if(cmp(heap[now],heap[next])) break;
		swap(heap[now],heap[next]);
		now=next;
	}
	return t;
}

void Put(int p){
	int now=++len,next;
	heap[len]=p;
	while(now>1){
		next=now>>1;
		if(!cmp(heap[now],heap[next])) break;
		swap(heap[now],heap[next]);	
		now=next;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	int t,n,m,a,b,k;
	scanf("%d",&t);
	while(t--){
		arcnum=1; k=0; len=0;
		memset(first,0,sizeof(first));
		memset(rd,0,sizeof(rd));
		memset(ans,0,sizeof(ans));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&a,&b);
			addarc(a,b);
			rd[b]++;
		}
		for(int i=1;i<=n;i++)
			if(rd[i]==0)
				Put(i);
		do{
			int u=Get(),v;
			ans[u]=++k;
			for(int p=first[u];p!=0;p=nxt[p]){
				v=go[p];
				if(--rd[v]==0)
					Put(v);
			}
		}while(len>0);
		if(k!=n) printf("-1\n");
		else{
			for(int i=1;i<=n;i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
	
	return 0;
}
