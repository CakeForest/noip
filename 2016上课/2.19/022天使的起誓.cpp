#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m[2000];//n���� m������ 
int main()//�߾���ȡģ ���߾��ȳ���ȡ������ 
{
	int len=0,ans;
	char a[2000];
	scanf("%d",&n);
	scanf("%s",a);
	for(int i=0;i<=strlen(a)-1;i++)
		m[i]=a[i]-'0';
	
	ans=m[0]%n;
	for(int j=1;j<=strlen(a)-1;j++)
		ans=(ans*10+m[j])%n;
		
	printf("%d",ans);
	
	
	return 0;
}
