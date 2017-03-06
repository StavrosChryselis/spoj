/*
****************************************************************
****************************************************************
-> Coded by Stavros Chryselis				   
-> Visit my github for more solved problems over multiple sites 
-> https://github.com/StavrosChryselis			  
-> Feel free to email me at stavrikios@gmail.com	
****************************************************************
****************************************************************
*/

#include <stdio.h>
#include <deque>
#include <algorithm>
#include <limits.h>
#include <ctype.h>
#define gc() getchar_unlocked()
 
using namespace std;
 
int N, CAP;
int A[10007];
 
inline int FAST_IO()
{
	char ch;
	int val = 0;
	ch = gc();
	while (isspace(ch) && ch != EOF)
		ch = gc();
	val = 0;
	while (isdigit(ch))
	{
		val = (val * 10) + (ch - '0');
		ch = gc();
	}
	return val;
}
 
inline void init()
{
	int i;
 
	N = FAST_IO();
	CAP = FAST_IO();
	for (i = 0; i < N; i++)
		A[i] = FAST_IO();
}
 
inline int solve()
{
	deque<int> Q;
	int i = 0;
	long long sum = 0;
	int MIN = INT_MAX;
 
	if (CAP == 0)
		return 0;
 
	while (i < N)
	{
		while (sum < CAP && i < N)
		{
			Q.push_back(A[i++]);
			sum += Q.back();
		}
 
		while (sum >= CAP && !Q.empty())
		{
			MIN = min(MIN, (int)Q.size());
			sum -= Q.front();
			Q.pop_front();
		}
	}
 
	while (sum >= CAP && !Q.empty())
	{
		MIN = min(MIN, (int)Q.size());
		sum -= Q.front();
		Q.pop_front();
	}
 
	if (MIN == INT_MAX)
		return -1;
 
	return MIN;
}
 
int main()
{
	int T, i;
 
	//freopen("input.txt", "r", stdin);
 
	T = FAST_IO();
 
	for (i = 1; i <= T; i++)
	{
		init();
		printf("Case %d: %d\n", i, solve());
	}
 
	return 0;
} 
