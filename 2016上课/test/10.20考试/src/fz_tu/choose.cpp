#include <stdio.h>
#include <algorithm>
#define MAXN 200010
using namespace std;
struct mayulong{
	int v;
}a[MAXN];
int f[MAXN],n,m;
int ext[MAXN];
void pybdeal(int x)
{
	//这是十个程序 
	if(x==m+1) return;
	for(int j=1;j<=n;j++) if(!ext[j]){
		int tmp=a[j].v;
		if(f[x]<f[x-1]+tmp){
			f[x]=f[x-1]+tmp;
			//printf("f[%d]==%d using a[%d]==%d %d\n",x,f[x],j,a[j].v,ext[8]);
			ext[j]++;
			if(j==1) ext[n]++;
			else ext[j-1]++;
			if(j==n) ext[1]++;
			else ext[j+1]++;
			pybdeal(x+1);
			if(ext[j]-1>=0) ext[j]--;
			else ext[j]=0;
			if(j==1){
				if(ext[n]-1>=0) ext[n]--;
				else ext[n]=0;
			}else if(ext[j-1]-1>=0) ext[j-1]--;
			else ext[j-1]=0;
			if(j==n){
				if(ext[1]-1>=0) ext[1]--;
				else ext[1]=0;
			}else if(ext[j+1]-1>=0) ext[j+1]--;
			else ext[j+1]=0;
		}
		
	}
}
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m>n/2){
		printf("Error!");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].v);
	}
	pybdeal(1);
	printf("%d",f[m]);
	return 0;
}
