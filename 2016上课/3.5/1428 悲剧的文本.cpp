#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<algorithm> 
using namespace std; 
struct node{ 
    node *next; 
    char now; 
}; 
//ÿ�ζ����ַ���ʹ�ò���ķ��������Ҹ����˽ڵ�֮ǰ�Ľڵ��ַ  
  
int main() 
{ 
    freopen("in.txt","r",stdin); 
    char c; 
    int sum[20]={0};//ͳ���ַ�����  
    node *p,*add; 
    node *head[20],*tail[20]; //ָ������ 
    head[1]=new node; 
    head[1]->next=new node;//ͷָ��  
    p=head[1];//��ǰָ��  
    tail[1]=head[1];//βָ��  
    int hang=1;//��ǰ����  
    bool flag=1;//��ǰ�Ƿ�����β 
    while(scanf("%c",&c)!=EOF) 
    { 
        if(c=='[')//������ͷ  
        { 
            if(flag)
				tail[hang]=p; 
            p=head[hang]; 
            flag=0;
            continue; 
        } 
        else if(c==']')//������β  
        { 
            p=tail[hang]; 
            flag=1;
            continue; 
        } 
        else if(c=='\n') 
        { 
            hang++; 
            head[hang]=new node; 
            head[hang]->next=new node;//ͷָ��  
            p=head[hang];//��ǰָ��  
            tail[hang]=head[hang];//βָ�� 
			flag=1; 
            continue;
        } 
        else
        { 
            sum[hang]++; 
            add=new node; 
            add->now=c; 
            add->next=p->next;//��p����һ���ڵ�����½ڵ�  
            p->next=add; 
            p=add;//����ڵ�  
        } 
    } 
      
    for(int i=1;i<=hang;i++) 
    { 
        p=head[i]->next; 
        for(int j=1;j<=sum[i];j++) 
        { 
            printf("%c",p->now); 
            p=p->next; 
        } 
        printf("\n"); 
    } 
      
    return 0; 
} 

