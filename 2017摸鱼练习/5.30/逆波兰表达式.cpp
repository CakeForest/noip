#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char str[100];

double calc(){
	scanf("%s",str);
	switch(str[0]){
		case '+':return calc()+calc();break;
		case '-':return calc()-calc();break;
		case '*':return calc()*calc();break;
		case '/':return calc()/calc();break;
		default:return atof(str);
	}
}

int main(){
	printf("%f",calc());
}
