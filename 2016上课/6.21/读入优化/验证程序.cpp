#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
#pragma warning(disable : 4996)
const int MAXN = 1000000;

inline int read()  
{  
	char ch;
	bool flag = false;
	int a = 0;  
	while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));
	if(ch != '-')
	{
		a *= 10;
		a += ch - '0';  
	}
	else
	{
		flag = true;
	}
	while(((ch = getchar()) >= '0') && (ch <= '9'))
	{
		a *= 10;
		a += ch - '0';
	}	
	if(flag)
	{
		a = -a;
	}
	return a;  
}  

void test1()
{
	int x;
	DWORD start_time, end_time;
	start_time = GetTickCount();
	for (int i = 1; i <= MAXN; i++)
	{
		x = read();
	
	}
	end_time = GetTickCount();
	printf("%lf\n", (end_time - start_time) / 1000.0);
}

void test2()
{
	int x;
	DWORD start_time, end_time;
	start_time = GetTickCount();
	for (int i = 1; i <= MAXN; i++)
	{
		//scanf("%d", &x);
		cin>>x;
	}
	end_time = GetTickCount();
	printf("%lf\n", (end_time - start_time) / 1000.0);
}

int main()
{
	freopen("in.txt", "r", stdin);	
//	test1();
	test2();
	return 0;
}
