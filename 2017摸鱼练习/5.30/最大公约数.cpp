#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int a,int b){
	if(!(a%b)) return b;
	return gcd(b,a%b);
}

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",gcd(a,b));
	
	
	
}
