#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<algorithm> 
using namespace std; 
struct node{ 
    node *next; 
    char now; 
}; 
//每次读入字符都使用插入的方法，并且给出此节点之前的节点地址  
  
int main() 
{ 
    freopen("in.txt","r",stdin); 
    char c; 
    int sum[20]={0};//统计字符个数  
    node *p,*add; 
    node *head[20],*tail[20]; //指针数组 
    head[1]=new node; 
    head[1]->next=new node;//头指针  
    p=head[1];//当前指针  
    tail[1]=head[1];//尾指针  
    int hang=1;//当前行数  
    bool flag=1;//当前是否是行尾 
    while(scanf("%c",&c)!=EOF) 
    { 
        if(c=='[')//跳到开头  
        { 
            if(flag)
				tail[hang]=p; 
            p=head[hang]; 
            flag=0;
            continue; 
        } 
        else if(c==']')//跳到结尾  
        { 
            p=tail[hang]; 
            flag=1;
            continue; 
        } 
        else if(c=='\n') 
        { 
            hang++; 
            head[hang]=new node; 
            head[hang]->next=new node;//头指针  
            p=head[hang];//当前指针  
            tail[hang]=head[hang];//尾指针 
			flag=1; 
            continue;
        } 
        else
        { 
            sum[hang]++; 
            add=new node; 
            add->now=c; 
            add->next=p->next;//在p的下一个节点加入新节点  
            p->next=add; 
            p=add;//插入节点  
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

