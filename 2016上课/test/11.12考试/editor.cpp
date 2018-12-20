#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	char c;
	int l,r;
}t[5000000];
int pnum,L,R;
int lcnt,rcnt;//存每个光标离最左侧的距离 
void move(bool dir,int p){//check
	if(!dir){//向左 
		if(!t[p].l) printf("F\n");
		else{
			int temp=t[p].l;
			t[p].l=t[temp].l;
			t[temp].r=t[p].r;
			t[p].r=temp;
			t[temp].l=p;
			t[t[p].l].r=p;
			t[t[temp].r].l=temp;
			printf("T\n");
			if(p==L) lcnt--;
			else rcnt--;
		}
	}else{//向右 
		if(!t[p].r) printf("F\n");
		else{
			int temp=t[p].r;
			t[p].r=t[temp].r;
			t[temp].l=t[p].l;
			t[p].l=temp;
			t[temp].r=p;
			t[t[p].r].l=p;
			t[t[temp].l].r=temp;
			printf("T\n");
			if(p==L) lcnt++;
			else rcnt++;
		}
	}
}

void insert(int p,int temp){//check
	t[t[p].l].r=temp;
	t[temp].l=t[p].l;
	t[temp].r=p;
	t[p].l=temp;
	printf("T\n");
	if(p==L){
		lcnt++;
		if(rcnt>lcnt) rcnt++;
	}else{
		rcnt++;
		if(lcnt>rcnt) lcnt++;
	}
}

void delet(int p){//check
	if(!t[p].r) printf("F\n");
	else{
		t[p].r=t[t[p].r].r;
		t[t[p].r].l=p;
		printf("T\n");
		//不会影响标记数组 
	}
}

void show(){//check
	for(int p=t[0].r;p;p=t[p].r){
		if(t[p].c) printf("%c",t[p].c);
	}
	printf("\n");
}

void Reverse(){
	if(lcnt+1>=rcnt) printf("F\n");
	else{
		int st=t[L].r,en=t[R].l;
		int p=st,temp=t[p].r;
		while(p!=R){
			swap(t[p].l,t[p].r);
			p=temp;
			temp=t[temp].r;
		}
		t[st].r=R;
		t[R].l=st;
		t[en].l=L;
		t[L].r=en;
		printf("T\n");
	}
}

int main(){
	freopen("editor.in","r",stdin);
	freopen("editor.out","w",stdout);

	L=++pnum;//初始化 
	char c=getchar();
	while(c!='\n'){
		t[++pnum].c=c;
		c=getchar();
	}
	R=++pnum;
	
	for(int i=L;i<=R;i++){
		t[i].l=i-1;
		t[i].r=i+1;
	}
	t[L].l=t[R].r=0;
	t[0].r=1;
	
	lcnt=1; rcnt=R;
	
	int N;
	scanf("%d",&N);
	while(N--){
		getchar();
		c=getchar();
		if(c=='<'){
			getchar();
			c=getchar();
			if(c=='L') move(0,L);
			else move(0,R);
		}else if(c=='>'){
			getchar();
			c=getchar();
			if(c=='L') move(1,L);
			else move(1,R);
		}else if(c=='I'){
			getchar();
			c=getchar();
			getchar();
			t[++pnum].c=getchar();
			if(c=='L') insert(L,pnum);
			else insert(R,pnum);
		}else if(c=='D'){
			getchar();
			c=getchar();
			if(c=='L') delet(L);
			else delet(R);
		}else if(c=='R'){
			Reverse();
		}else if(c=='S'){
			show();
		}
	}
	return 0;
}
