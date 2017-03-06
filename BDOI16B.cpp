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
#include <string.h>
#include <algorithm>
 
#define MAXN 100000000
using namespace std;
 
vector<pair<int, int> > factors;
int N, K;
 
 
inline void factorize(int num)
{
	if (num % 2 == 0)
	{
		factors.push_back(make_pair(2, 0));
 
		while (num % 2 == 0)
		{
			num /= 2;
			factors.back().second++;
		}
	}
 
	for (int i = 3; i <= num; i += 2)
	{
		if (num % i == 0)
		{
			factors.push_back(make_pair(i, 0));
 
			while (num % i == 0)
			{
				num /= i;
				factors.back().second++;
			}
		}
	}
}
 
inline void init()
{
	factors.clear();
 
	scanf("%d %d", &N, &K);
	factorize(K);
}
 
inline int get_max_pow(int factor)
{
	int i;
	int rval = 0;
 
	for (i = factor; i <= N; i *= factor)
		rval += N / i;
 
	return rval;
}
 
inline int solve()
{
	int rval = MAXN;
	int i;
 
	for (i = 0; i < factors.size(); i++)
		rval = min(rval, get_max_pow(factors[i].first) / factors[i].second);
 
	return rval;
}
 
int main()
{
	int T, t;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	for (t = 1; t <= T; t++)
	{
		init();
		printf("Case %d: %d\n", t, solve());
	}
 
	return 0;
} 
