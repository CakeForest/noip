#include<cstdio>

const int maxn=100000+100;

int d[maxn],l[maxn],r[maxn];
int len;

int look(int c,int rt){
	if(rt==0) return 0;
	if(d[rt]==c) return rt;
	if(d[rt]<c) return look(c,r[rt]);
	else return look(c,l[rt]);
}

int newnode(int c){
	d[++len]=c;
	return len;
}

void insert(int c,int rt){
	
	if(d[rt]<c) {
		if(r[rt]==0)
			r[rt]=newnode(c); 
		else insert(c,r[rt]);
	}else{
		if(l[rt]==0)
			l[rt]=newnode(c);
		else insert(c,l[rt]);
	}
}

int main()
{
	int n;
	freopen("BST10.in","r",stdin);
	freopen("BST10.out","w",stdout);
	scanf("%d",&n);
	len=1;
	scanf("%d",&d[1]);
	printf("no\n");
	int c;
	for(int i=2;i<=n;i++){
		scanf("%d",&c);
		if(look(c,1)){
			printf("yes\n");
		}else{
			printf("no\n");
			insert(c,1);
		}
			
	}
	return 0;
} 
