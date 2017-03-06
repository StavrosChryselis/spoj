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
 
#define gc() getchar_unlocked()
using namespace std;
 
int K[2007], KE[2007];
string S;
 
inline void getstring(string &A)
{
	A.clear();
	A.push_back('0');
 
	char c = gc();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}
 
inline int solve()
{
	int i;
	int ans = 0;
 
	for (i = 1; i < S.size(); i++)
	{
		switch (S[i])
		{
		case 'K':
			K[i] = K[i - 1] + 1;
			KE[i] = KE[i - 1];
			ans += KE[i];
			break;
 
		case 'E':
			K[i] = K[i - 1];
			KE[i] = KE[i - 1] + K[i];
			break;
		default:
			K[i] = K[i - 1];
			KE[i] = KE[i - 1];
		}
	}
 
	return ans;
}
 
int main()
{
	int T;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	while (T--)
	{
		getstring(S);
		printf("%d\n", solve());
	}
 
	return 0;
}
 
 
