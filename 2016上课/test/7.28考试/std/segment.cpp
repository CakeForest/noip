#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
 
int xian[1000001][3];
int n,zfg;
 
int swap(int *a,int *b){
    int tmp;
    if(*a>*b){
       tmp=*a;
       *a=*b;
       *b=tmp;
    }
    return 1;
}
 
void output(){
     int i;
     for(i=1;i<=n;i++){
        printf("%d %d %d\n",xian[i][0],xian[i][1],xian[i][2]);
     }     
}
 
void countd(){
     int i,j;
     int z,y;
     zfg=0;
     for(i=1;i<=n;i++){
        z=xian[i][0];
        y=xian[i][1];
        for(j=1;j<=n;j++){
           if(i==j) continue;
           if(xian[j][0]<y && xian[j][1]>z)
              xian[i][2]++;
        }
        zfg+=xian[i][2];
     }  
}
 
void swapArray(int i,int j){
     int t[3];
     t[0]=xian[i][0];
     t[1]=xian[i][1];
     t[2]=xian[i][2];
     xian[i][0]=xian[j][0];
     xian[i][1]=xian[j][1];
     xian[i][2]=xian[j][2];     
     xian[j][0]=t[0];
     xian[j][1]=t[1];
     xian[j][2]=t[2];
}
 
void quickSort(int z,int y){
    int i,j,t;
    int pos;
    if(z>=y) return ;
    t=rand()%(y-z+1)+z;
    swapArray(t,z);
    i=z;
    j=y;
    pos=i;
    j++;
    while(1){
       while( xian[++i][1]<xian[pos][1] && i<y) ;
       while(xian[--j][1]>xian[pos][1]) ;
       if(i>=j) break;
       swapArray(i,j);                   
    }
    swapArray(pos,j);
    
    quickSort(z,j-1);
    quickSort(j+1,y);
}
 
 
 
int main(){
    int i,j,z,y;
     freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
     
    scanf("%d",&n);
   // memset(xian,0,sizeof(xian));
    for(i=1;i<=n;i++){
       scanf("%d  %d",&z,&y);
       swap(&z,&y);
       xian[i][0]=z;
       xian[i][1]=y;                  
    }
     // output();
    //countd();
    quickSort(1,n);
   // output(); 
    z=1;
    y=xian[1][1];
    for(i=2;i<=n;i++){
      if(xian[i][0]>y){
         y=xian[i][1];
         z++;
      }
    }
     
     
    printf("%d",z);
    
    return 0;    
}
 
