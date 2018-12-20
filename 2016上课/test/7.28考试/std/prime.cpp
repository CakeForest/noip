#include<stdio.h>
#include<string.h>
int a[1000];
int p(int a){
	int i,flag=0;
	for(i=2;i<=a/2;i++){
		if(a%i==0){
			flag=1;
			break;
		}
	}
	if(flag==1)
	return 1;
	else
	return 0;
}
int f[40000]={0};
int out(int n){
	int i=1,j,k;
	memset(f,0,sizeof(f));
	f[0]=1;
	while(a[i]<=n){
		i++;
	}
	k=i;
	for(i=1;i<k;i++){
		for(j=1;j<=n;j++){
			if(j>=a[i])
			f[j]=f[j]+f[j-a[i]];
		}
    }
    return f[n];
}
int main(){
	int i,j,n,k=1;
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	for(i=2;i<=300;i++){
		if(p(i)==0){
			a[k]=i;
		    k++;
		    //printf("%d ",i);
		}
	}
//	for(int t=1;t<=100;t++) printf("%d ",a[t]);
//	printf("fdsa");
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",out(n));
	}
	
}
