#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=5000000;
char str[20020],data[MAX];
int first[MAX],nxt[MAX],go[MAX],exist[MAX],dist[MAX],strsum[MAX],pnum=1,arcnum;
int stack[MAX],top;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

int u,len;
int Find(int len){//������ҵ��ͷ���0 δ�ҵ�ʱ���ص�һλδƥ���λ�� 
	int v,nextpoi;
	u=1;
	for(int i=1;i<=len;i++){
		nextpoi=-1;
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			if(data[v]==str[i]){
				nextpoi=v;
				break;
			}
		}
		if(nextpoi!=-1) u=nextpoi;
		else return i;//��iλ��ʱƥ����� 
	}
	if(!exist[u]) return len+1;//��Ȼ�н�㣬����û�д����� 
	return 0;//�ɹ��ҵ��ַ��� 
} 

void Insert(int t){//���ַ�����tλ�ÿ�ʼ���� 
	if(t==len+1){//�н�㣬����û������ 
		exist[u]=1;
		return; 
	}
	for(int i=t;i<=len;i++){
		addarc(u,++pnum);
		data[pnum]=str[i];
		dist[pnum]=dist[u]+1;
		u=pnum; 
	}
	exist[u]=1;//��ǵ�ǰ�ַ����Ľ�β 
}

int GetStrSum(int u){
	if(first[u]==0) return exist[u];
	for(int p=first[u];p!=0;p=nxt[p])
		strsum[u]+=GetStrSum(go[p]);
	return exist[u]+strsum[u];
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,t,maxx=-1;
	scanf("%d",&n); getchar();
	for(int i=1;i<=n;i++){//���ַ��������ֵ��� 
		gets(str+1);
		len=strlen(str+1);
		if(t=Find(len)) Insert(t);
	}
	
	GetStrSum(1);
	
/*	for(int i=1;i<=pnum;i++)
		printf("%d ",strsum[i]);
	printf("\n\n\n");*/
	
	for(int p=2;p<=pnum;p++)//ö����ʼ�� 
		maxx=max(maxx,strsum[p]*dist[p]);
	printf("%d",maxx);
	
	return 0;
}
