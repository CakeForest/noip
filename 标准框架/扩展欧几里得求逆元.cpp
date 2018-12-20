#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//Çó³ý·¨ÄæÔª 

//(a/b)%c=((a%c)*inv(b))%c

void exgcd(int a,int b,int c,int &x,int &y){
	if(!a){x=0;y=c/b;}
	else{exgcd(b%a,a,c,x,y);y=x;x=(c-b*y)/a;}
}

int main(){
	int a,mod,x,y;
	scanf("%d%d",&a,&mod);
	exgcd(a,mod,1,x,y);
	printf("%d",x);
	
	
	return 0;
}
