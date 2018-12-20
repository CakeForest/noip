#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
	double data;
	int character;
}heap[60];
char str[1000];
int num[60],loc[60],len,n,sum;
double val[60];
bool cmp(node a,node b)
{
	return a.data<b.data;
}

char change(char c)
{
	if(c>='A'&&c<='Z')
		return c-'A';
	if(c>='a'&&c<='z')
		return c-'a'+26;
	return 52;
}

void Put(double val,int t)
{
	int now=++len,next;
	heap[now].data=val;
	heap[now].character=t;
	while(now>1)
	{
		next=now/2;
		if(cmp(heap[now],heap[next]))
			swap(heap[now],heap[next]);
		else break;
		now=next;
	}
	
}

node Get()
{
	int now=1,next;
	node t=heap[1];
	heap[1]=heap[len--];
	while(now*2<=len)
	{
		next=now*2;
		if(next<len&&cmp(heap[next+1],heap[next])) next++;
		if(cmp(heap[now],heap[next])) break;
		swap(heap[now],heap[next]);
		now=next;
	}
	return t;
}

int main()
{
	freopen("in.txt","r",stdin);
	char ending[]="END";
	while(1)
	{
		scanf("%s",str+1);
		if(strcmp(str+1,ending)==0) break;
		n=strlen(str+1); len=0; sum=0;//初始化 
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)//统计各字符出现次数 
			num[change(str[i])]++;
		for(int i=0;i<=52;i++)
			if(num[i]!=0)
				Put(1.0*num[i]/n,i),sum++;//将出现过的字符加入堆中 
		for(int i=n;i>=1;)
		{
			node a=Get(),b=Get();//取频率最小的两个字符 
			loc[i--]=a.character;
			loc[i--]=b.character;
			Put(a.data+b.data,-1);
		}
		
		int tot=0;
		for(int i=1;i<=n;i++){//统计所有字母的哈夫曼编码长度 
			if(loc[i]==-1)
				continue;
			tot+=num[loc[i]]*log(i)/log(2);
		}
		printf("%d %d %.1f\n",n*8,tot,8.0*n/tot);
	}
	
	
	return 0;
}
