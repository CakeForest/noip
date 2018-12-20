#include<cstdio>
#include<cmath>
#include<cstring>
const int MAX=10010;
int prime[MAX],vis[MAX],cnt,e[MAX];
void get_prime(){
	for(int i=2;i<=10000;i++){
		if(!vis[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*prime[j]>10000) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}

void prime_divide(int k,int add){
	int now=1;
	while(k>=prime[now]){
		while(k%prime[now]==0){
			k/=prime[now];
			e[now]+=add;
		}
		now++;
		if(k==1) break;
	}
}

void add_fact(int n,int d){
	for(int i=1;i<=n;i++)
		prime_divide(i,d);
}

void print_ans(){
	double ans=1;
	for(int i=1;i<=cnt;i++)
		ans*=pow(prime[i],e[i]);
	printf("%.5lf\n",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	int p,q,r,s;
	get_prime();
	while(~scanf("%d%d%d%d",&p,&q,&r,&s)){
		memset(e,0,sizeof(e));
		add_fact(p,1);
		add_fact(q,-1);
		add_fact(p-q,-1);
		add_fact(r,-1);
		add_fact(s,1);
		add_fact(r-s,1);
		print_ans();
	}
	
	return 0;
}
