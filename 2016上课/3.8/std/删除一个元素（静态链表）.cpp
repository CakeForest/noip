#include <cstdio>

const int maxn = 10000;

int date[maxn],next[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&date[i]);
		next[i]=i+1;
	}
	next[0]=1;
	next[n+1]=-1;
	
	int m;
	scanf("%d",&m);
	int p,q;

	for(q=0,p=next[0];p!=n+1;p=next[p]){
		if(date[p]==m){
			next[q]=next[p];			
		}else
			q=p;
	}
	for(p=next[0];p!=n+1;p=next[p])
		printf("%d ",date[p]);
	return 0;
	
}
