#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char k[2000],mw[2000];
int lenk,lenm;
char translate(char mw,char key){
	int k=key-'a';
	
	if(mw>='A'&&mw<='Z'){
		mw-=k;
		if(mw<'A') mw+=26;
	}else{
		mw-=k;
		if(mw<'a') mw+=26;
	}
	return mw;
}

int main(){
	freopen("vigenere.in","r",stdin);
	freopen("vigenere.out","w",stdout);
	
	scanf("%s%s",k+1,mw+1);
	lenk=strlen(k+1);//密钥长度 
	lenm=strlen(mw+1);//密文长度 
	
	for(int i=1;i<=lenk;i++)
		if(k[i]>='A'&&k[i]<='Z') k[i]+=32;
	
	int now=1;
	for(int i=1;i<=lenm;i++){
		printf("%c",translate(mw[i],k[now++]));
		if(now>lenk) now=1;
	}
	
	
	return 0;
}
