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
#include <string>
#include <ctype.h>
#include <algorithm>
 
#define gc() getchar_unlocked()
 
using namespace std;
 
int dist[26];
string S;
int C;
 
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
 
inline void init_dist()
{
	dist['G' - 'A'] = 1;
	dist['R' - 'A'] = 2;
	dist['Y' - 'A'] = 3;
	dist['B' - 'A'] = 4;
	dist['O' - 'A'] = 5;
}
 
inline int cost(char a, char b)
{
	a = dist[a - 'A'];
	b = dist[b - 'A'];
 
	if (a > b)
		return a - b;
 
	return b - a;
}
 
inline void init()
{
	scanf("%d", &C);
	getstring(S);
}
 
inline int solve()
{
	int i, j, c = 0;
	int MAX = 1;
 
	i = 0;
	j = 1;
 
	while (j < S.length())
	{
		while (j < S.length() && cost(S[j], S[j - 1]) + c <= C)
		{
			c += cost(S[j], S[j - 1]);
			j++;
			MAX = max(MAX, j - i);
		}
 
		if (j == S.length())
			break;
 
		while (c + cost(S[j], S[j - 1]) > C)
		{
			c -= cost(S[i], S[i + 1]);
			i++;
		}
	}
 
	return MAX;
}
 
int main()
{
	int T, i;
 
	//freopen("input.txt", "r", stdin);
 
	init_dist();
 
	scanf("%d", &T);
 
	for (i = 1; i <= T; i++)
	{
		init();
		printf("Scenario #%d: %d\n", i, solve());
	}
 
	return 0;
} 
