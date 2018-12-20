#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char s[400],s1[20],s2[20];
	char in[1000];
	gets(in);
	int i=0,k=0,j=1;
	while(in[i]!=0)
	{
		if(in[i]!=',')
		{
			if(j==1)
				s[k]=in[i];
			else if(j==2)
				s1[k]=in[i];
			else
				s2[k]=in[i];
			k++;
		}
		else
		{
			if(j==1)
				s[k]=0;
			else if(j==2)
				s1[k]=0;
			k=0;j++;
		}
		i++;
	}
	s2[k]=0;


    i=0;
	int llen=strlen(s1);
	
	
	while(s[i]!=0&&s[i+llen]!=0)//’“s1Œª÷√ 
	{
		if(s[i]==s1[0]&&s[i+llen-1]==s1[llen-1])
		{
			for(int j=1;j<=llen-1;j++)
			{
				if(s[i+j]!=s1[j])
					break;
				if(j==llen-1)
				{
					goto a;
				}
			}
		}
		i++;
	}
	printf("-1");
	return 0;
	a:int left=i+llen;
	
	i=strlen(s)-1;
	int rlen=strlen(s2);
	while(s[i-rlen]!=0&&s[i]!=0)//’“s2Œª÷√ 
	{
		if(s[i]==s2[rlen-1]&&s[i-rlen+1]==s2[0])//////
		{
			for(int j=1;j<=rlen-1;j++)
			{
				if(s[i-j]!=s2[rlen-j-1])
					break;
				if(j==rlen-1)
				{
					goto b;
				}
			}
		}
		i--;
	}
	printf("-1");
	return 0;		
	b:int right=i-rlen+2;
	
	int distance=right-left-1;
	if(distance<0)
	{
		printf("-1");
		return 0;
	}
	else
	{
		printf("%d",distance);
	}
	
	
	return 0;
}