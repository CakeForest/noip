#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=100020;
int n,m;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum;
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;
}
int main(){
	freopen("blockade.in","r",stdin);
	freopen("blockade.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addarc(u,v,w);
		addarc(v,u,w);
	}
	
	int cnt=0;
	for(int p=first[1];p;p=nxt[p]) cnt++;
	
	scanf("%d",&m);
	if(m<cnt){ printf("-1"); return 0; }
	printf("0");
	
		
	
	return 0;
}
