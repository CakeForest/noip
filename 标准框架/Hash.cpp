#include<cstdio>
using namespace std;
const int MAX=10000000;
int ht[MAX+10];
int Hash1(char *str){
	int P=1e9+7;
	int seed=131;
	int h=0;
	while(*str) h=(h*seed+(*str++))%P;
	return h; 
}
int Hash2(char *str){
	int P=1e7+1;
	int seed=13;
	int h=0;
	while(*str) h=(h*seed+(*str++))%P;
	return h; 
}
int Insert(char *str){
	int h=Hash1(str);
	int ad=Hash2(str);//作为地址 
	
	while(ht[ad]){
		if(ht[ad]==h) return 0;
		ad=(ad+233)%MAX;//记住超过最大值要取模 
	}
	return ht[ad]=h;
}
int main(){
//	freopen("in.txt","r",stdin);
	char str[1000];
	while(scanf("%s",str)){
		if(Insert(str)) printf("insert success\n\n");
		else printf("has been\n\n");
	}
	
	return 0;
}
