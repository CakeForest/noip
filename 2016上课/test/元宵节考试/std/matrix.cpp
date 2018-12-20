#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;


int main(){
	 int n,wi,wj; 
	 freopen("matrix.in","r",stdin);
	 freopen("matrix.out","w",stdout) ;
	 scanf("%d%d%d",&n,&wi,&wj);
	 
	 int cs=min(min(wi,wj),min(n-wi+1,n-wj+1));
	 
	 int qd=1;
	 for(int i=1;i<cs;i++){
	 	qd+=(n-1-(i-1)*2)*4;
	 	//printf("%d\n",qd);
	 }
//	 printf("%d %d\n",cs,qd);
	 
	 int i=cs,j=cs;
	 int fx=1;
	 while((i!=wi || j!=wj) && fx!=0){
	 	//printf("%d %d\n",qd,fx);
	 	if(fx==1){
	 		
	 		j++;
	 		qd++;
	 		if(j>n-cs+1){
	 			j--;
	 			qd--;
	 			fx=2;
	 		}
	 	}
	 	if(fx==2){
	 		i++;
	 		qd++;
	 		if(i>n-cs+1){
	 			i--;
	 			qd--;
	 			fx=3;
	 		}
	 	}
	 	if(fx==3){
	 		j--;
	 		qd++;
	 		if(j<cs){
	 			j++;
	 			qd--;
	 			fx=4;
	 		}
	 	}
	 	if(fx==4){
	 		i--;
	 		qd++;
	 		if(i<cs){
	 			i++;
	 			qd--;
	 			fx=0;
	 		}
	 	}
	 }
	 
	 printf("%d",qd);
	 
	 
	 return 0;
}
