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
#include <vector>
#include <algorithm>
#include <ctype.h>
 
#define gc() getchar_unlocked()
using namespace std;
 
int N, K;
 
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
 
inline int solve()
{
	vector<int> V;
	vector<int>::iterator ii;
 
	int i, num;
 
	N = FAST_IO();
	num = FAST_IO();
	V.push_back(num);
 
	for (i = 0; i < N - 1; i++)
	{
		num = FAST_IO();
 
		if (num > V.back())
			V.push_back(num);
 
		else
		{
			ii = lower_bound(V.begin(), V.end(), num);
			*ii = num;
		}
	}
 
	K = FAST_IO();
 
	if (K > V.size())
		return -1;
 
	return V[K - 1];
}
 
int main()
{
	int T;
 
	T = FAST_IO();
 
	while (T--)
	{
		printf("%d\n", solve());
	}
 
	return 0;
} 
