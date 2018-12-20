#include <iostream>  
#include <cstdio>  
#include <windows.h>  
#include <cstdlib>  
#include <ctime>  
using namespace std;  
const int MAXN = 1000000;  
  
int main()  
{  
    freopen("in.txt", "w", stdout);  
    srand((unsigned)time(NULL));  
    for (int i = 1; i <= MAXN; i++)  
    {  
        printf("%d\n", rand());  
    }  
    return 0;  
}  
