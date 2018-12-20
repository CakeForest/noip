#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000+5;
char s[maxn];
int last,cur,next[maxn];
int main()
{
    while(scanf("%s",s+1) != EOF ) {
        int n = strlen(s+1);
        last = cur = 0;
        next[0] = 0; //next[0]�൱�ڿ�ָ��head 
        for(int i = 1 ; i <= n ; i ++) {
            char ch = s[i];
            if(ch == '[') cur = 0;
            else if(ch == ']') cur = last;
            else {
                next[i] = next[cur];
                next[cur] = i;
                if(cur == last) last = i;
                cur = i;
            }
        }
        for(int i = next[0] ; i != 0 ; i = next[i]) {
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
