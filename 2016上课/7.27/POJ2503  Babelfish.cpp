#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000000;
char data[MAX+20][11],s1[11],s2[11];
unsigned int hashtable[MAX+20];
unsigned int Hash1(const char* str){ 
	unsigned int h=0;
	unsigned int seed=31;
	while(*str) h+=(h*seed+(*str++))%MAX;
	return (h%MAX+h+1311)%MAX;
}

unsigned int Hash2(const char* str){
	unsigned int h=0;
	unsigned int seed=131;
	while(*str) h+=(h*seed+(*str++))%(MAX+3);
	return h%MAX;
}


int main(){
//	freopen("in.txt","r",stdin);
	unsigned int h1,h2;
	while(scanf("%s",s1)!=EOF){
		if(getchar()!=' ') break;
		scanf("%s",s2);
		h1=Hash1(s2);
		h2=Hash2(s2);
		while(data[h1][0]!=0){
			if(h2==hashtable[h1]) break;
			h1+=2333;
			if(h1>MAX) h1%=MAX;
		}
		hashtable[h1]=h2;
		strcpy(data[h1],s1);
	}
	do{
		h1=Hash1(s1);
		h2=Hash2(s1);
		while(h2!=hashtable[h1]){
			if(data[h1][0]==0) break;
			h1+=2333;
			if(h1>MAX) h1%=MAX;
		}
		if(data[h1][0]==0) printf("eh\n");
		else printf("%s\n",data[h1]);
	}while(scanf("%s",s1)!=EOF);
	
	
	return 0;
}
