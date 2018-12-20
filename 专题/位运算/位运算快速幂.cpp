#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int pow(int a,int b,int c)
{
    int r=1,base=a;
    while(b!=0){
        if(b&1)//如果是奇数 
			r*=base;//单独乘一次 
        base*=base;//base^2
        b>>=1;//幂指数右移 
    }
    return r%c;//取模返回 
}

int main()
{
	//freopen("in.txt","r",stdin);
	int a,b,c;//a^b%c
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",pow(a,b,c));
	
	return 0;
}
