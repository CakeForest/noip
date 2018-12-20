#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt[40],maxx;
char str[100];
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	while(scanf("%s",str)!=EOF){
		for(int i=0;str[i];i++)
			if(str[i]>='A'&&str[i]<='Z'){
				cnt[str[i]-'A'+1]++;
				maxx=max(maxx,cnt[str[i]-'A'+1]);
			}
	}
	
	for(int i=maxx;i>=1;i--){
		for(int j=1;j<=25;j++){
			printf("%c ",cnt[j]>=i?'*':' ');
		}
		printf("%c\n",cnt[26]>=i?'*':' ');
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	
	
	return 0;
}
