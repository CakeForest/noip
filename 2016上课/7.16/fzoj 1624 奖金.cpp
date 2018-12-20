#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=300000;
int first[MAX],nxt[MAX],go[MAX],arcnum=1,rd[MAX];
int stack[MAX],val[MAX],top;
void addarc(int a,int b){
	nxt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum++]=b;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,a,b,k=0,tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		addarc(b,a);//b比a工资低 
		rd[a]++;//入度+1 
	}
	for(int i=1;i<=n;i++)
		if(rd[i]==0)//将入度为0的点入栈 
			stack[++top]=i;
	while(top!=0){
		int now=stack[top--];//当前点 
		k++; tot+=100+val[now]; 
		for(int p=first[now];p!=0;p=nxt[p]){
			val[go[p]]=max(val[go[p]],val[now]+1);//不应当在入度为0时才更新val[]，而应当每次都更新，取最大值 
			if(--rd[go[p]]==0)
				stack[++top]=go[p];
			}
	}
	
	if(k==n) printf("%d",tot);
	else printf("Poor Xed");
	
	
	return 0;
	
}


