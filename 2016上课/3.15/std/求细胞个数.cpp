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
//	freopen("in.txt","r",stdin); //ע��������ַ������룬ʹ���ļ������Բ��ܸ�׼ȷ 
	scanf("%d %d",&n,&m);
	getchar();//�˴�����һ�еĻ��ж��룻 
	int i,j,t;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			c = getchar();	
			//�˴��и����ɣ�map[][]����Ϊȫ�������ÿ��Ԫ�ض����ʼ��Ϊ0
			//�����±��1��ʼ����ô����ʹ�õ�����ͽ��ᱻһȦ 0��Χ����������� 
			if(c!='0')
				map[i][j]=1;
		}	
		getchar();//�˴���ÿ�еĽ����Ļ��ж��� 
	}
	/* ��������󣬼�ס������½�� 
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
