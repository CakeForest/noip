#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int MyScanf(){
	int a=0,flag=0;
	char ch;
	ch=getchar();
	if(ch=='-') flag=1;
	else a=ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9'){
		a=a*10+ch-'0';
		ch=getchar();
	}
	if(flag) a=-a;
	return a;
}

int main()
{
	freopen("in.txt","r",stdin);
	printf("%d",MyScanf());
	
	return 0;
}
