#include <cstdio>
#include <cstring>
int n;
char neck[1000],necki[1000];
int place;

char nextPlace(){
	int newp=place+1;
	if(newp>=n) newp=0;
	place=newp;
	return neck[place]; 
}

char prePlace(){
	int newp=place-1;
	if(newp<0) newp=n-1;
	place=newp;
	return neck[place]; 
}

char nowPlace(){
	return neck[place]; 
}

void sel(){
	necki[place]=1;
}

using namespace std;
int main() {
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	scanf("%d\n",&n);
	scanf("%s",neck);
	
	int max=0,maxi;
	int zzs,yzs;//左边总共的珠子个数，右边总共的珠子个数 
	for(int i=0;i<n;i++){
		//从i与i-1之间断开；
		char target;//目标珠子
		yzs=0;
		place=i;
		memset(necki,0,sizeof(necki));
		while(nowPlace()=='w' && !necki[place]){
			necki[place]=1;
			nextPlace();
		
			yzs++;
		} 
		target=nowPlace();
		while( (nowPlace()=='w' || nowPlace()==target) &&  !necki[place] ){
		//	printf("%c",nowPlace());
			yzs++;
			necki[place]=1;
			nextPlace();
		}
		//printf("\n------------------\n");
		place=i-1;
		zzs=0;
		if(place<0) place=n-1;
		while(nowPlace()=='w' && !necki[place] ){
		//	printf("%c",nowPlace());
			necki[place]=1;
			prePlace();
			zzs++;
		} 
		target=nowPlace();
		while(  (nowPlace()=='w' || nowPlace()==target)  && !necki[place] ){
		//	printf("%c",nowPlace());
			necki[place]=1;
			zzs++;
			prePlace();
		}
		if(yzs+zzs>max) {
			maxi=i;
			max=yzs+zzs;
		}
		
	}
	printf("%d\n",max);
	return 0;
}
