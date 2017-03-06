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
#include <ctype.h>
#include <string>
 
#define MOD 1000000007
#define gc() getchar()
 
using namespace std;
 
long long powers[100007];
string A, B;
int N;
 
inline void preinit()
{
	int i;
 
	powers[0] = 1;
 
	for (i = 1; i <= 100000; i++)
	{
		powers[i] = powers[i - 1] * 2;
		powers[i] %= MOD;
	}
}
 
inline void getstring(string &A)
{
	char c;
 
	A.clear();
 
	c = gc();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}
 
inline void init()
{
	getstring(A);
	getstring(B);
	N = A.length();
}
 
inline long long solve(string &A, string &B)
{
	int i;
	long long sum = 0;
 
	for (i = 0; i < N && A[i] >= B[i]; i++)
	{
		if (A[i] == '1')
		{
			sum += powers[N - i - 1];
			sum %= MOD;
		}
	}
 
	if (i == N)
	{
		if (A[0] == B[0])
			return sum;
 
		if (A[i - 1] == '1' && B[i - 1] == '0')
		{
			sum -= 1;
			if (sum < 0)
				sum += MOD;
			return sum;
		}
	}
 
	for (; i < N; i++)
		if (B[i] == '1')
		{
			sum += powers[N - i - 1];
			sum %= MOD;
		}
 
	return sum;
}
 
int main()
{
	int T, i;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	preinit();
 
	for (i = 1; i <= T; i++)
	{
		init();
 
		if (A > B)
			printf("Case %d: %lld\n", i, solve(A, B));
		else
			printf("Case %d: %lld\n", i, solve(B, A));
	}
 
	return 0;
} 
