#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int ans[10000];
long long cifang(long x,int n,char c)//算十进制权  x进制 n第几位数  
{
	int sum=1;
	for(int i=1;i<=n;i++)
		sum*=x;
	int now;
	switch(c)
	{
		case 'A':now=10;break;
		case 'B':now=11;break;
		case 'C':now=12;break;
		case 'D':now=13;break;
		case 'E':now=14;break;
		case 'F':now=15;break;
		default:now=c-'0';
	}
	return sum*now;
}

int jinzhi(long long n,int y)//n十进制 y目标进制 
{
	int i=0;
	if(n==0)
	{
		ans[i]=0;
		return i;
	}
	do{
		ans[i]=n%y;
		n/=y;
		i++;
	}while(n>=y);
	ans[i]=n;
	return i;
}

int main()
{
	int x,y;
	char input[1000];
	scanf("%d %s %d",&x,input,&y);
	int len=strlen(input);
	for(int i=0;i<=len-1;i++)//转换成大写 
		if(input[i]>='a'&&input[i]<='z')
			input[i]-='a'-'A';
	long long ten=0;
	for(int i=0;i<=len-1;i++)	//转换成十进制权 
		ten+=cifang(x,len-i-1,input[i]);
	
	for(int i=jinzhi(ten,y);i>=0;i--)//转换为y进制 
		switch(ans[i])
		{
			case 10:printf("A");break;
			case 11:printf("B");break;
			case 12:printf("C");break;
			case 13:printf("D");break;
			case 14:printf("E");break;
			case 15:printf("F");break;
			default:printf("%d",ans[i]);break;
		}
	
	return 0;
}