#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int head,nxt[1000000],cnum;
char go[1000000];
void add(int x,char c){
	if(x==0){
		nxt[++cnum]=head;
		head=cnum;
		go[cnum]=c;
		return;
	}
	int p=head,last=head;
	for(int i=1;i<=x;i++,p=nxt[p])
		last=p;
	nxt[++cnum]=p;
	nxt[last]=cnum;
	go[cnum]=c;
}

void print(){
	if(!go[head]){
		printf("-");
		return;
	}
	for(int i=head;i!=0;i=nxt[i])
		printf("%c",go[i]);
}

void update(){
	bool flag;
	int cnt=0,prefirst=0,last=0;
	do{
		cnt=prefirst=last=0;
		flag=0;
		char p=go[head];//上一次的元素 
		if(p==0) return;//无元素
		for(int i=head;i!=0;i=nxt[i]){
			if(p==go[i]) cnt++;
			else if(cnt>=3){
				if(!prefirst) head=i;//当前的头被消掉，i作头 
				else nxt[prefirst]=i;//去掉链
				cnt=1; flag=1;
			}else{
				prefirst=last;
				cnt=1; p=go[i];
			}
			last=i;
		}
		if(cnt>=3){
			if(!prefirst) head=0;//当前的头被消掉，i作头 
			else nxt[prefirst]=0;//去掉链
			flag=1;
		}
		
	}while(flag);
	
}

int main(){
	freopen("hao.in","r",stdin);
	freopen("hao.out","w",stdout);
	
	scanf("%s",go+1); head=1;
	cnum=strlen(go+1)+1;
	for(int i=2;i<=strlen(go+1);i++) nxt[i-1]=i;
	
	int cas;
	scanf("%d",&cas);
	while(cas--){
		char c; int t;
		scanf("%d",&t);

		
		getchar();c=getchar();
		add(t,c); 

		
		update();
		print(); printf("\n");
	}
	
	
	return 0;
}
