#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	double h;
	int gend;
}t[50];
char str[30];

bool cmp(node a,node b){
	if(a.gend!=b.gend) return a.gend==1;//ÄĞĞÔÔÚ×ó 
	if(a.gend==1) return a.h<b.h;
	return a.h>b.h;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s %lf",str,&t[i].h);
		t[i].gend=str[0]=='m';
	}
	
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;i++)
		printf("%.2f ",t[i].h);
	
}
