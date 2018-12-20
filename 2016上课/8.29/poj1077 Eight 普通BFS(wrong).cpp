#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=600000;
const int key=123046758;//目标状态 
int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
int tpow[]={0,1e8,1e7,1e6,1e5,1e4,1e3,1e2,1e1,1};
int que[MAX],vis[MAX],step[MAX],father[MAX],top,rear;
int ans[MAX];
int contor(int t){
	int s[10],n=9;//将数字生成数组
	for(int i=n;i>=1;i--){s[i]=t%10;t/=10;}
	int sum=0,k;
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i+1;j<=n;j++)
			if(s[i]>s[j]) k++;
		sum+=k*fac[n-i];
	}
	return sum;//范围0~n!-1 
}
int getint(){
	char c;
	while(1){
		c=getchar();
		if(c=='x') return 0;
		if('0'<=c&&c<='9') return c-'0';
	}
}
int findloc(int t){//找到x的位置 
	for(int i=9;i>=1;i--)
		if(t%10==0) return i;
		else t/=10;
	return 0;
}
int left(int t){//check
	int p=findloc(t),temp;
	if(p==1||p==4||p==7) return 0;
	temp=t/tpow[p-1]%10;
	t-=temp*tpow[p-1];
	return t+temp*tpow[p];
}

int right(int t){//check
 	int p=findloc(t),temp;
	if(p==3||p==6||p==9) return 0;
	temp=t/tpow[p+1]%10;
	t-=temp*tpow[p+1];
	return t+temp*tpow[p];
}

int down(int t){//check
	int p=findloc(t),temp;
	if(p==7||p==8||p==9) return 0;
	temp=t/tpow[p+3]%10;
	t-=temp*tpow[p+3];
	return t+temp*tpow[p];
}

int up(int t){//check
	int p=findloc(t),temp;
	if(p==1||p==2||p==3) return 0;
	temp=t/tpow[p-3]%10;
	t-=temp*tpow[p-3];
	return t+temp*tpow[p];
}

char translate(int t){
	switch(t){
		case 0:return 'l';
		case 1:return 'r';
		case 2:return 'u';
		case 3:return 'd';
	}
	return 0;
}

void print(int u){
	int cnt=1; ans[1]=step[u];
	while(father[u]!=-1){
		u=father[u];
		ans[++cnt]=step[u];
	}
	for(int i=cnt;i>=2;i--)
		printf("%c",translate(ans[i]));
}

int BFS(int n){
	top=rear=0;
	que[rear++]=n;
	father[0]=-1;
	do{
		int u=que[top],t;
		vis[contor(u)]=1;
		if(u==key){print(top);return 1;}
		t=left(u); if(t!=0){que[rear]=t;step[rear]=0;father[rear++]=top;}
		t=right(u); if(t!=0){que[rear]=t;step[rear]=1;father[rear++]=top;}
		t=up(u); if(t!=0){que[rear]=t;step[rear]=2;father[rear++]=top;}
		t=down(u); if(t!=0){que[rear]=t;step[rear]=3;father[rear++]=top;}
		top++;
		
	}while(top!=rear);
	return 0;
}

void hs(int use[],int temp,int t){
	if(t==10){
		if(vis[contor(temp)]) printf("%d!",temp);
		else vis[contor(temp)]=1;
		return;
	}
	for(int i=0;i<=9;i++){
		if(!use[i]){
			use[i]=1;
			hs(use,temp+i*tpow[t],t+1);
			use[i]=0;
		}
		
	}
}

int main(){
	freopen("in.txt","r",stdin);
	
	int n=0,c,a=100000000;
	for(int i=1;i<=9;i++){
		c=getint();
		n+=a*c;
		a/=10;
	}
	if(!BFS(n)) printf("unsolvable\n");
	
//	for(int i=0;i<=top;i++) printf("%d\n",que[i]);
//	printf("%d",right(12345678));
	
/*	
	int use[10]={0};
	hs(use,0,1);*/
	
	
	return 0;
}
