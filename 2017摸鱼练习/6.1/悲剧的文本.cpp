#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX=100020;
const int S=1,E=2;
int nxt[MAX],pre[MAX],P,t;
char d[100020],c;

void print(){
	P=nxt[S];
	while(P!=E){
		printf("%c",d[P]);
		P=nxt[P];
	}
	
	printf("\n");
}

void Init(){
	P=S;
	nxt[S]=E;
	pre[E]=S;
	t=2;
}

int main(){
	Init();
	while(scanf("%c",&c)!=EOF){
		if(c=='\n'){
			print();
			Init();
			continue;
		}
		if(c=='[')//¿ªÍ· 
			P=S;
		else if(c==']')//½áÎ²
			P=pre[E];
		else{
			d[++t]=c;
			nxt[t]=nxt[P];
			pre[nxt[P]]=t;
			nxt[P]=t;
			pre[t]=P;
			P=t;
		}	
	}
	print();
	
	
}
