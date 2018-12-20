#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
const int MAXN=100+20,MAXL=150+2,MAXM=20+10;

char word[MAXN][MAXL];
char s[MAXL];
int n,f[MAXL][MAXL][MAXL],g[MAXL][MAXL][MAXL],ql,ans;
char q[MAXL][MAXL];

int isend(){
	char end[]="LAST CASE";
	int l=strlen(end);
	for(int i=0;i<l;i++)
		if(end[i]!=s[i+1]) return 0;
	return 1;
}

int pd(int p){
	int ql=strlen(q[p]+1);
	int j;
	for(int i=1;i<=n;i++){
		int wl=strlen(word[i]);
		if(wl!=ql) continue;
		for(j=0;j<wl;j++){
			if(word[i][j]!=tolower(q[p][j+1])) break;
		}
		if(j>=wl) return 0;//返回0说明第p个要被过滤 
	}
	return 1;//返回1说明第p个不要被过滤 
}

void filter(){
	int sl=strlen(s+1)+1;
	ql=0;
	int qi=1;
	s[sl]=' ';
	for(int i=1;i<=sl;i++){
		if(s[i]!=' ')
			q[ql][qi++]=s[i];
		else{
			q[ql][qi++]=0;
			if(ql==0||pd(ql)) ql++;
			qi=1;
		}
	}
}

void dp(){
	memset(f,0,sizeof(f));
	int labb;
	labb=strlen(q[0]+1);
	char abbr[MAXL];
	for(int i=1;i<=labb;i++)
		abbr[i]=tolower(q[0][i]);
	f[0][0][1]=1;
	for(int i=1;i<=labb;i++) g[0][0][i]=1;	
	for(int i=1;i<=labb;i++)
	for(int j=1;j<=ql;j++){
		int qll=strlen(q[j]+1);
		for(int k=1;k<=qll;k++){
			if(q[0][i]==toupper(q[j][k])){
				int qll2=strlen(q[j-1]+1);
				f[i][j][k]+=g[i-1][j][k-1];
				f[i][j][k]+=g[i-1][j-1][qll2];
				
				/*
				for(int kk=1;kk<k;kk++)
					f[i][j][k]+=f[i-1][j][kk];
				
				for(int kk=1;kk<=qll2;kk++)
					f[i][j][k]+=f[i-1][j-1][kk];
					*/
			//	if(i==1 && f[i][j][k]==0) f[i][j][k]=1;
			//	printf("%d %d %d %d \n",i,j,k,f[i][j][k]);
			}
			g[i][j][k]=g[i][j][k-1]+f[i][j][k];
		}
	}
	int qll=strlen(q[ql]+1);
	ans=0;
	for(int i=1;i<=qll;i++)
		if(q[0][labb]==toupper(q[ql][i]))
		ans+=f[labb][ql][i];
} 

int main()
{
	freopen("abbr.in","r",stdin);
	freopen("abbr.out","w",stdout);
	scanf("%d\n",&n); 
	for(int i=1;i<=n;i++){
		scanf("%s",word[i]);
	}
//	for(int i=1;i<=n;i++) printf("%s\n",word[i]);
	char c;
	while((c=getchar())=='\n');
	int p=1;
	s[p]=c;
	while(1){
		
		while((c=getchar())!='\n') s[++p]=c;
		s[p+1]=0;
	//	printf("%s\n",s+1);
		if(isend()) break;
		filter();//q[0]是大写字母缩写，1之后是过滤后的每个单词； 
		ql--;
		
		/*
		printf("%d\n",ql);
		for(int j=1;j<=ql;j++)
			printf("%s\n",q[j]+1) ;
		*/
		

		dp();
		if(ans==0)
			printf("%s is not a valid abbreviation\n",q[0]+1);
		else
			printf("%s can be formed in %d ways\n",q[0]+1,ans);
		p=0;
	}
}
