#include<cstdio>
#include<cstring>
const int MAX=1000;

int s1[MAX]={1},s2[MAX],L=1;
char str[MAX];

void intcpy(){
	for(int i=0;i<=L-1;i++)
		s1[i]=s2[i];
}

void calc(){
	memset(s2,0,sizeof(s2));
	for(int i=0;i<=L-1;i++){
		int t=s1[i]*2;
		if(t>9) s2[i+1]++,t-=10;
		s2[i]+=t;
	}
	if(s2[L]) L++;
	intcpy();
	
}

int main(){
	int N;
	scanf("%d",&N);
	while(N--) calc();
	
	for(int i=L-1;i>=0;i--)
		printf("%d",s1[i]);
	
}
