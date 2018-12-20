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
int Find(int len){//如果查找到就返回0 未找到时返回第一位未匹配的位置 
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
		else return i;//在i位置时匹配错误 
	}
	if(!exist[u]) return len+1;//虽然有结点，但是没有存数据 
	return 0;//成功找到字符串 
} 

void Insert(int t){//从字符串的t位置开始插入 
	if(t==len+1){//有结点，但是没有数据 
		exist[u]=1;
		return; 
	}
	for(int i=t;i<=len;i++){
		addarc(u,++pnum);
		data[pnum]=str[i];
		u=pnum; 
	}
	exist[u]=1;//标记当前字符串的结尾 
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,t,maxx=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){//将字符串插入字典树 
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
