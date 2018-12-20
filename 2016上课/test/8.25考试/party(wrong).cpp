#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000;
char per[30],bos[30];
int HashTable[1000010],happy[MAX];
int first[MAX],nxt[MAX],go[MAX],arcnum;
int f[MAX][2],que[MAX],top,rear;
int Hash(char *str){
	int seed=131;
	int P=1000001;
	int h;
	while(*str) h=(seed*h+(*str++))%P;
	return h;
}
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

int main(){
	freopen("party.in","r",stdin);
//	freopen("party.out","w",stdout);
	int n,hap,now=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s%d%s",per,&hap,bos);
		int h,person,boss;
		h=Hash(per);
		if(!HashTable[h]) HashTable[h]=now++;
		person=HashTable[h];
		happy[person]=hap;
		
		h=Hash(bos);
		if(!HashTable[h]) HashTable[h]=now++;
		boss=HashTable[h];
		
		addarc(boss,person);
	}
	
	char start[]="NOBODY\0";
	que[rear++]=HashTable[Hash(start)];
	do{
		int u=que[top++],v;
		for(int p=first[u];p;p=nxt[p])
			que[rear++]=go[p];	
	}while(top!=rear);
	
	for(int i=top;i>=2;i--){
		int u=que[i],v;
		for(int p=first[u];p;p=nxt[p]){
			v=go[p];
			f[u][0]=max(f[u][0],max(f[v][0],f[v][1])+happy[u]);
			f[u][1]=max(f[u][1],f[v][0]+happy[u]);
		}
	}
	int ans=0;
	for(int p=first[que[1]];p;p=nxt[p]){
		int v=go[p];
		ans+=max(f[v][0],f[v][1]);
	}
	printf("%d",ans);
	
	return 0;
}
