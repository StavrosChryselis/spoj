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
#include <algorithm>
#include <unordered_map>
#include <string>
 
#define gc() getchar_unlocked()
 
using namespace std;
 
string S;
 
struct rolling_hash 
{
	static const unsigned long long p = 1000000007ull;
	string s;
	int n;
	vector<long long> pow, phash;
	rolling_hash(string s) : s(s), n(s.length()), pow(n+1), phash(n+1)
	{
		pow[0] = 1; 
		phash[0] = 0;
 
		for (int i = 0; i < n; ++i)
		{
			phash[i+1] = s[i] + phash[i] * p;
			pow[i+1] = pow[i] * p;
		}
	}
 
	long long hash(int i, int j) 
	{
		return phash[j] - phash[i] * pow[j-i];
	}
 
};
 
inline bool init()
{
	char c;
 
	S.clear();
 
	c = gc();
 
	if(c == '\n')
		return 0;
 
	while(c!='\n')
	{
		if(c != ' ')
			S.push_back(c);
		c = gc();
	}
 
	return 1;
}
 
inline void solve()
{
	int i, j;
	rolling_hash RL(S);
	unordered_map<long long, int> memo;
	int MAX = 0;
 
	for(i = 1; i <= S.length(); i++)
	{
		MAX = 0;
		for(j = 0; j + i <= S.length(); j++)
		{
			memo[RL.hash(j, j + i)]++;
			MAX = max(MAX, memo[RL.hash(j, j + i)]);
		}
 
		if(MAX == 1)
			return;
 
		printf("%d\n", MAX);
	}
}
 
int main()
{
	//freopen("input.txt","r", stdin);
 
	while(init())
	{
		solve();
		printf("\n");
	}
 
	return 0;
} 
