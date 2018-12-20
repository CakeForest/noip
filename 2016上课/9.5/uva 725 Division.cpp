#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,tot;
int judge(int t1,int t2){
	int vis[10]={0};
	for(int i=1;i<=5;i++){
		vis[t1%10]++;
		if(vis[t1%10]>1) return 0;
		t1/=10;
	}
	for(int i=1;i<=5;i++){
		vis[t2%10]++;
		if(vis[t2%10]>1) return 0;
		t2/=10;
	}
	return 1;
}

void print(int n){
	if(n/10000==0) printf("0");
	printf("%d",n);
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	int flag=1;
	while(cin>>n&&n){
		if(flag) flag=0;
		else printf("\n");
		tot=0;
		for(int i=10000;i<=99999;i++){
			if(judge(i,i/n)&&i%n==0){
				tot++;
				print(i);
				printf(" / ");
				print(i/n);
				printf(" = %d\n",n);
			}
		}
		if(!tot) printf("There are no solutions for %d.\n",n);
	}
	
	return 0;
}
