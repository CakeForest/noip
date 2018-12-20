#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[1000];
	gets(a);
	int len=strlen(a)-1;//数组元素个数
	int k=0,j=len;
	while(k<=j){
		if(a[k]!=a[j])
		{
			printf("no");
			return 0;
		}
		k++;j--;	
	} 
	printf("yes");
	
	return 0;
}