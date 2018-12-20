#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=3000000;
char str[220],data[MAX],kind[5];
int first[MAX],nxt[MAX],go[MAX],exist[MAX],pnum=1,arcnum;
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
		u=pnum; 
	}
	exist[u]=1;//��ǵ�ǰ�ַ����Ľ�β 
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,t,maxx=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){//���ַ��������ֵ��� 
		scanf("%s",kind); getchar();
		gets(str+1);
		len=strlen(str+1);
		if(kind[0]=='a')
			Insert(Find(len));
		else{
			t=Find(len);
			if(t==0) printf("yes\n");
			else printf("no\n");
		}
	}
	
	
	return 0;
}
