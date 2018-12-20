#include<stdio.h>
int main(){
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	int v=0,s=0,t1=0,t2=0,n,m;
	int a[1001],p[1001],q[1001],t[1001],bj[1001];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>0) t1+=a[i];
		if(a[i]<0) t2+=a[i];
	}
	if(t1!=0-t2){
		printf("Impossible");
		return 0;
	}
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&p[i],&q[i],&t[i]);
	while(true){
		int min=0x3f3f3f3f,k;
		for(int i=1;i<=m;i++){
			if(bj[i]!=1)
				if(t[i]<min){
					k=i;
					min=t[i];
				}
	    }
		s+=min;
	    if(bj[k]!=1){
	    	if(bj[p[k]]!=1)
	    	    v++;
	    	if(bj[q[k]]!=1)
	    	    v++;
			
	    }
	    if(v>=m){
	    	printf("%d",s);
	    	return 0;
	    }
	}
}
