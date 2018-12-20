#include<cstdio>
#include<cstring>
const int MAX=300;

int s1[MAX],s2[MAX],L1,L2;
char str[MAX];

void my_input(int *p,int *t){
	scanf("%s",str);
	*t =strlen(str);
	for(int i=*t-1;i>=0;i--)
		*p++=str[i]-'0';
}

int main(){
	my_input(s1,&L1);
	my_input(s2,&L2);
	
	for(int i=0;i<=L1-1;i++){
		int t=s1[i]-s2[i];
		if(t<0)	s1[i+1]--,t+=10;
		s1[i]=t;
	}
	
	for(int i=L1-1;i>=0;i--)
		printf("%d",s1[i]);
}
