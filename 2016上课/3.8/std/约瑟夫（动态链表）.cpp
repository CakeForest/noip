#include <cstdio>
#include <cstdlib>

struct node{
	int date;
	node *next;
};

int main(){
	int n,m,i;
	node *p,*q,*head;
	while(scanf("%d %d",&n,&m)!=EOF && n && m){
		head=new node;
		head->date=1;
		p=head;
		for(i=2;i<=n;i++){
			p->next=new node;
			p=p->next;
			p->date=i;
		}	
		p->next=head;
		q=p;
		p=head;	
		while(p->next!=p){
			i=1;
			while(i!=m){
				q=p;
				p=p->next;
				i++;
			}
			q->next=q->next->next;
			delete p;
			p=q->next;
				
		}
		printf("%d\n",p->date);
	}
	
	return 0;

}

