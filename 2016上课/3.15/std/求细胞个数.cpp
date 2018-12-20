#include <cstdio>

int map[30][30];
int movex[]={0,0,1,-1}, movey[]={1,-1,0,0};
struct node{
	int x,y;
};

node que[1000];
int head,tail;

int main()
{
	int n,m;
	char c;
//	freopen("in.txt","r",stdin); //注意对于有字符的输入，使用文件，调试才能更准确 
	scanf("%d %d",&n,&m);
	getchar();//此处将第一行的换行读入； 
	int i,j,t;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			c = getchar();	
			//此处有个技巧，map[][]定义为全局数组后，每个元素都会初始化为0
			//并且下标从1开始，那么我们使用的数组就将会被一圈 0包围；方便操作。 
			if(c!='0')
				map[i][j]=1;
		}	
		getchar();//此处将每行的结束的换行读入 
	}
	/* 读入结束后，记住输出看下结果 
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%d",map[i][j]);
		}	
		printf("\n");
		
	}
	*/ 
	
	int z=0;
	head=1;
	tail=1;
	node kz,zz;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(map[i][j]==1){
				z++;
				que[tail].x=i;
				que[tail++].y=j;
				do{
					kz=que[head++];
					for(t=0;t<4;t++){
						zz.x=kz.x+movex[t];
						zz.y=kz.y+movey[t];
						if(map[ zz.x ][ zz.y ] == 1){
							 
							que[tail++]=zz;
							map[ zz.x ][ zz.y ] = 0;
						}
					}
				}while(tail!=head);
			}
		}	
	}
	printf("%d",z);	
} 
