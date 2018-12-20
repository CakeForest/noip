#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Choose{
	int n1,n2,n3;
}ch[200001];
int bj[200001],lj[200001];
int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(m<<1>=n) printf("Error!");
	for(int i=1;i<=n;i++){
		scanf("%d",&ch[i].n2);
		lj[i]=ch[i].n2;
	}
	sort(lj,lj+n);
/*	for(int i=1;i<=n;i++){
		ch[i].n1=ch[i-1].n2;
		ch[i].n3=ch[i+1].n2;
	}
	int s=0;
	int t,l;
	for(int j=1;j<=m;j++){
		memset(bj,0,sizeof(bj));
		bj[l]=1;
		for(int i=n;i>=1;i++){
		    if(bj[i]!=1){
		    	if(t<=lj[i]){
		    		t=lj[i];
		    		bj[i-1]=1;
		    		bj[i]=1;
		    		l=t;
		    	}
		    }
	    }
	    s+=t;
	}
	printf("%d",s);*/
	return 0;
}
