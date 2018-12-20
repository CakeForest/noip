#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char longest[101],shortest[101];
void comp(char str[])
{
	if(strlen(str)>strlen(longest))
		strcpy(longest,str);
	if(strlen(str)<strlen(shortest))
		strcpy(shortest,str);
}


int main()
{
	char a[21000];
	bool fuck=1;
	gets(a);
	char x[200];int y=0;
	int i=0;
	do{
		if(a[i]!=','&&a[i]!=' '&&a[i]!=0)
		{
			x[y]=a[i];
			y++;
		}
		else if(y!=0)
		{
			x[y]=0;
			if(fuck)
			{
				strcpy(longest,x);
				strcpy(shortest,x);
				fuck=0;
			}
			else
				comp(x);
			y=0;
		}
		if(a[i]==0)
			break;
		i++;
	}while(1);
	
	printf("%s\n",longest);
	printf("%s",shortest);
	
	return 0;
}