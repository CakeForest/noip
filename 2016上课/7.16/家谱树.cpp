#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000;
int first[MAX],nxt[MAX],go[MAX],arcnum=1;
int rd[MAX],stack[MAX],top;
void addarc(int a,int b){
	nxt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum++]=b;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		while(scanf("%d",&m)!=EOF &&m!=0)
			addarc(i,m),rd[m]++;
	for(int i=1;i<=n;i++)
		if(rd[i]==0)
			stack[++top]=i;
	do{
		int now=stack[top--];
		printf("%d ",now);
		for(int p=first[now];p!=0;p=nxt[p]){
			rd[go[p]]--;
			if(rd[go[p]]==0)
				stack[++top]=go[p];
		}
	}while(top!=0);
	
	
	return 0;
}
