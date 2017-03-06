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
 
#define gc() getchar()
using namespace std;
 
string S, T;
 
inline void getstring(string &A)
{
	char c;
 
	A.clear();
 
	c = gc();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c))
	{
		A.push_back(c);
		c = gc();
	}
}
 
inline void solve()
{
	int i, j;
 
	for (i = 0; i < S.length(); i++)
	{
		if (isalpha(S[i]))
			T.push_back(S[i]);
		else
		{
			string temp = T;
 
			for (j = 0; j < S[i] - '0' - 1; j++)
				T += temp;
		}
	}
}
 
int main()
{
	int t, Q, num;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &t);
 
	while (t--)
	{
		T.clear();
		getstring(S);
		solve();
 
		scanf("%d", &Q);
 
		while (Q--)
		{
			scanf("%d", &num);
			if (num > T.length())
				printf("-1\n");
			else
				printf("%c\n", T[num - 1]);
		}
	}
 
	return 0;
} 
