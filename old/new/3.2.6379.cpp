#include<cstdio>  
#include<cstring> 
#include<algorithm>
using namespace std;
struct node{
	char id[20];
	char name[20];
	char sex;
	int old;
	char score[20];
	char addr[20];
}data[2000];


int main() 
{ 
	int pre[2000];
	int p=1,last=0;
	do{
		scanf("%s",data[p].id);
		if(strcmp(data[p].id,"end")==0)
		{
			p--;
			break;
		}
		scanf("%s %c %d %s %s",data[p].name,&data[p].sex,&data[p].old,data[p].score,data[p].addr);
		pre[p]=last;
		last=p;
		p++;
	}while(1);
	
	for(int i=p;i>=1;i=pre[i])
		printf("%s %s %c %d %s %s\n",data[i].id,data[i].name,data[i].sex,data[i].old,data[i].score,data[i].addr);
	
	return 0; 
} 

