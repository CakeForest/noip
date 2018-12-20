#include<cstdio>  
#include<cstring> 


char data[20000];
int next[20000];

int sum=0;
void pri()
{
	int p=next[0];
	for(int i=1;i<=sum;i++)
	{
		printf("%c",data[p]);
		p=next[p];
	}
	printf("\n");
	sum=0;
}

int main() 
{ 
    char c;
    bool end=1; 
    int cur=1,tail=0,p=0;//p:指针 ，在data[0]之后添加数据 
	next[0]=1;
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')
		{
			pri();
			end=1;cur=1;tail=0;p=0;next[0]=1;
		}
		else if(c=='[')
		{
			p=0;
			end=0;
		}
		else if(c==']')
		{
			p=tail;
			end=1;
		}
		else
		{
			sum++;
			data[cur]=c;
			next[cur]=next[p];
			next[p]=cur;
			if(end)
			{
				tail=cur;
			}
			p=next[p];
			cur++;
			
		}
		
	}
      
    return 0; 
} 

