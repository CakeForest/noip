#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int pow(int a,int b,int c)
{
    int r=1,base=a;
    while(b!=0){
        if(b&1)//��������� 
			r*=base;//������һ�� 
        base*=base;//base^2
        b>>=1;//��ָ������ 
    }
    return r%c;//ȡģ���� 
}

int main()
{
	//freopen("in.txt","r",stdin);
	int a,b,c;//a^b%c
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",pow(a,b,c));
	
	return 0;
}
