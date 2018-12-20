#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000000;
char str[200];
int data[MAX+200],log[10000000],tot;

int Translate(char c){
	if(c>='0'&&c<='9') return c-'0';
	if(c=='Q'||c=='Z'||c=='-') return -1;
	if(c<='P') return (c-'A')/3+2;
	return (c-'A'-1)/3+2;
}

int Hash(char* str){
	int k=1000000,sum=0,a;
	do{
		if((a=Translate(*str))!=-1){
			sum+=k*a;
			k/=10;
		}	
	}while(*str++);
	return sum;
}

void Print(int data,int tot){
	int p[7]={0,0,0,0,0,0,0},k=1000000;
	for(int i=0;i<=6;i++){
		p[i]=data/k;
		data%=k;
		k/=10;
	}
	for(int i=0;i<=2;i++)
		printf("%d",p[i]);
	printf("-");
	for(int i=3;i<=6;i++)
		printf("%d",p[i]);
	printf(" %d\n",tot);
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,h;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		h=Hash(str);
		if(data[h]==1) log[++tot]=h;
		data[h]++;
	}
	sort(log+1,log+1+tot);
	for(int i=1;i<=tot;i++)
		Print(log[i],data[log[i]]);
	if(tot==0)
		printf("No duplicates.");
	
/*	printf("%d",Translate('M'));
	char sr[10]="ITS-EASY";
	printf("%d",Hash(sr));*/
	
	
	return 0;
}
