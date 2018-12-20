#include<cstdio>
int inline readint(){
	int Num=0,Flag=1;char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') break;
	if(ch=='-') Flag=-1;else Num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') Num=Num*10+ch-'0';
	return Num*Flag;
}

int main(){
	int t=readint();
	printf("%d",t);
	
}
