#include <cstdio>
 
int que[10000],s[1000],h[1000];
int head,tail,qd;
int map[30][30];
 
void out(int zd){
    int sc[30],j=0,i;
//  for(int i=1;i<=zd;i++) printf("%d ",h[i]); 
    sc[j++]=zd; 
    for(i=h[zd];i!=-1;i=h[i]) sc[j++]=i;
         
//  for(int i=0;i<j;i++) printf("@%d ",sc[i]); 
    printf("%c",qd+'A'-1);
    for(int i=j-2;i>=0;i--)
        printf("->%c",sc[i]+'A'-1);

}
 
int main(){
    int sl,a,b,n=0,zd;
     
    scanf("%d %d %d",&qd,&zd,&sl);
//  printf("%d %d %d",qd,zd,sl);
    while(sl--){
        scanf("%d %d",&a,&b);
        if(n<a) n=a;
        if(n<b) n=b;
        map[a][b]=1;
        map[b][a]=1;
    }
    que[head]=qd;
    h[qd]=-1;
    tail++;
    s[qd]=1;
    do{
        int tz=que[head];
        head++;
        //printf("%d\n",tz);
        for(int i=1;i<=n;i++){
            if(map[tz][i]==1 && s[i]!=1){
                if(i==zd){
                    h[i]=tz;
                    out(zd);
                    return 0;;
                }
                s[i]=1;
                que[tail]=i;
                tail++;
                h[i]=tz;
            }
        }
    }while(head!=tail);
/*  */
    return 0;
     
} 
