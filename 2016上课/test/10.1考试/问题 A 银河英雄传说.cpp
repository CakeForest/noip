#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f
#define MAXN 1000005
using namespace std;

/*
����:����N������,����Ҫ����N������֮��ҡ��,ֱ���������Ҷ˵���һ������,������Ҫ
     ҡ�ڶ��ٴ�. ҡ�ڵ�ʱ�����ڿ�ʼ��ʱ������Ǵ�ĳһ��ҡ�ڵ�ĳ���ԳƵĵ�ʱ,��
     ֤���е����ӵĸ߶Ȳ����ڳ�����ĸ߶�.
     
�ⷨ:��dp[i]��ʾ��x����Ϊiʱ������Ҫ������ҡ�ڴ���.������һ��׼���������Ǽ����
     ÿ�����ӵ�һ���ɽ�������.����Ľ���Ƕ��ڵ�k�����ӷ�Χ��[ ceil(Xk-sqrt(2*Yk*Y1-Y1*Y1)), Xk-1 ]
     Ȼ���ÿ���������ܹ����ܵ������ڽ��ж�̬�滮
     dp[i] = max(dp[k] + 1), ����Ҫ��k��i�����ӽ��ܵ������� 
*/

int N, dp[MAXN];

struct Node {
 