#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[1000];
int tag,end;

void into(int a,int b){
	bool ok=0; int cnt=0;
	for(int i=b;i>=a;i--){
		if(str[i]=='0'&&!ok) continue;
		printf("%c",str[i]); cnt++;
		if(str[i]!='0') ok=1;
	}
	if(!cnt) printf("0");
}

void doubleo(){
	into(1,tag-1);
	printf(".");
	for(int i=tag+1;i<end;i++){
		if(str[i]=='0') tag++;
		else break;
	}
	into(tag+1,end);
}

void feno(){
	into(1,tag-1);
	printf("/");
	into(tag+1,end);
}

void pero(){
	into(1,tag-1);
	printf("%c",'%');
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	int flag=0; char c;
	int i=1;
	while(scanf("%c",&c)!=EOF){
		switch(c){
			case '.':flag=1;tag=i;break;
			case '/':flag=2;tag=i;break;
			case '%':flag=3;tag=i;break;
			default:str[i]=c;
		}
		end=i++;
	}
	
//	printf("flag:%d tag:%d",flag,tag);
	switch(flag){
		case 0:into(1,end);break;
		case 1:doubleo();break;
		case 2:feno();break;
		case 3:pero();break;
	}
	
	return 0;
}
