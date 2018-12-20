#include <cstdio>
#include <cstring>
struct pieces{
	char d[6][6];
};
pieces origina,solv;
int xmove[]={0,0,0,-1,1},ymove[]={0,1,-1,0,0};
int col1[5],initcount,count;

char reverse(char c){
	if(c=='b') return 'w';
	if(c=='w') return 'b';
}

int checkxy(int x,int y)
{
	if(x>4 || y>4) return 0;
	if(x<1 || y<1) return 0;
	return 1;
}

int flip(int x,int y){
	count++;
	solv.d[x][y]=reverse(solv.d[x][y]);
	for(int i=1;i<=4;i++){
		if( checkxy(x+xmove[i],y+ymove[i]) )
				solv.d[ x+xmove[i] ][ y+ymove[i] ]=reverse(solv.d[x+xmove[i]][y+ymove[i]]);
	}
}

void init()
{
	count=0;
	for (int i = 1; i <= 4; ++i){
		for (int j = 1; j <= 4; ++j){
			solv.d[i][j]=origina.d[i][j];
		}
		
	}

	for (int i = 1; i <= 4; ++i){
		if(col1[i]==1){
			flip(1,i);			
		}
	}
}

int flipprocess(char target){

	for (int i = 2; i <= 4; ++i){
		for (int j = 1; j <= 4; ++j){
			if(solv.d[i-1][j] != target ){
				flip(i,j);
			}
		}
	}
	for (int i = 1; i <= 4; ++i){
		if(solv.d[4][i] != target ){
			return 0;	
		}
	}
	return 1;
}

int main(){
	
	int res=9999999;
	int i,j;
	for ( i = 1; i <= 4; ++i){
		for ( j = 1; j <= 4; ++j){
			
				scanf("%c",&origina.d[i][j]);
		}
		origina.d[i][j]='\0';
		getchar();
	}
	int num=0;
	
	for( col1[1]=0;col1[1]<=1;col1[1]++)
	for( col1[2]=0;col1[2]<=1;col1[2]++)
	for( col1[3]=0;col1[3]<=1;col1[3]++)
	for( col1[4]=0;col1[4]<=1;col1[4]++){
		init();

		if(flipprocess('w')) {
			if(res>count) res=count;
		}
		init();

		if(flipprocess('b')) {
			if(res>count) res=count;
		}
		num++;
		
	}
	if(res!=9999999)
		printf("%d",res);
	else
		printf("Impossible");
	return 0;
} 
