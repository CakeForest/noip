#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int first[2000],next[2000],go[2000],arcnum=1,n,m;
void addarc(int a,int b){
	go[arcnum]=b;
	next[arcnum]=first[a];
	first[a]=arcnum;
	arcnum++;
}
int look[2000][2000];//记录某条边是否被遍历 
bool judge(int a,int b){
	if(a>b) swap(a,b);
	return look[a][b]==0;
}

void log(int a,int b,int k){
	if(a>b) swap(a,b);
	look[a][b]=k;
}


int ans[2000];//记录走法 
int hs(int poi,int t){
	ans[t]=poi;
	if(t==m) return 1;
	for(int p=first[poi];p!=0;p=next[p]){
		if(judge(poi,go[p])==0) continue;
		log(poi,go[p],1);
		if(hs(go[p],t+1)) return 1;
		log(poi,go[p],0);
	}
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y; scanf("%d%d",&x,&y);
		addarc(x,y);addarc(y,x);
	}
	for(int i=1;i<=n;i++)
		if(hs(i,1)){
			for(int j=1;j<=n;j++) printf("%d ",ans[j]);
			for(int p=first[ans[m]];p!=0;p=next[p])
				if(go[p]==i) 
					printf("%d",i);
			return 0;
		}

}
