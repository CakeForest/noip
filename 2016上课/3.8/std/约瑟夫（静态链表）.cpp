#include <cstdio>
#include <cstdlib>

const int maxn=500;
int date[maxn],next[maxn];

int main(){
	int n,m,i;
	int p,q,head;
	while(scanf("%d %d",&n,&m)!=EOF && n && m){
		
		for(i=1;i<=n;i++){
			next[i]=i+1;
			//ע�⣬�˴�date[i]=i�����ֱ�������±���Ϊ�����򼴿ɣ� 
		}
		next[n]=1;
		
		p=1;
		q=n;
		while(next[p]!=p){
			i=1;
			while(i!=m){
				q=p;
				p=next[p];
				i++;
			}
			next[q]=next[p];
			p=next[q];
				
		}
		printf("%d\n",p);
	}
	
	return 0;

}

