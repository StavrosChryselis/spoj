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
#include <string.h>
#include <ctype.h>
#include <string>
 
#define gc() getchar_unlocked()
using namespace std;
 
bool memo[26][26][26][26][26][26];
 
inline void getstring(string &A)
{
	char c = gc();
 
	A.clear();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}
 
inline char nextchar()
{
	char c = gc();
 
	while (isspace(c))
		c = gc();
 
	return c;
}
 
inline void insert(string &A)
{
	memo[A[0] - 'a'][A[1] - 'a'][A[2] - 'a'][A[3] - 'a'][A[4] - 'a'][A[5] - 'a'] = 1;
}
 
inline void query(string &A)
{
	int i;
 
	for (i = 'a'; i < A[0]; i++)
		if (memo[i - 'a'][A[1] - 'a'][A[2] - 'a'][A[3] - 'a'][A[4] - 'a'][A[5] - 'a'])
		{
			A[0] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	for (i = 'a'; i < A[1]; i++)
		if (memo[A[0] - 'a'][i - 'a'][A[2] - 'a'][A[3] - 'a'][A[4] - 'a'][A[5] - 'a'])
		{
			A[1] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	for (i = 'a'; i < A[2]; i++)
		if (memo[A[0] - 'a'][A[1] - 'a'][i - 'a'][A[3] - 'a'][A[4] - 'a'][A[5] - 'a'])
		{
			A[2] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	for (i = 'a'; i < A[3]; i++)
		if (memo[A[0] - 'a'][A[1] - 'a'][A[2] - 'a'][i - 'a'][A[4] - 'a'][A[5] - 'a'])
		{
			A[3] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	for (i = 'a'; i < A[4]; i++)
		if (memo[A[0] - 'a'][A[1] - 'a'][A[2] - 'a'][A[3] - 'a'][i - 'a'][A[5] - 'a'])
		{
			A[4] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	for (i = 'a'; i < A[5]; i++)
		if (memo[A[0] - 'a'][A[1] - 'a'][A[2] - 'a'][A[3] - 'a'][A[4] - 'a'][i - 'a'])
		{
			A[5] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	//bigger
 
	for (i = A[5] + 1; i <= 'z'; i++)
		if (memo[A[0] - 'a'][A[1] - 'a'][A[2] - 'a'][A[3] - 'a'][A[4] - 'a'][i - 'a'])
		{
			A[5] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	for (i = A[4] + 1; i <= 'z'; i++)
		if (memo[A[0] - 'a'][A[1] - 'a'][A[2] - 'a'][A[3] - 'a'][i - 'a'][A[5] - 'a'])
		{
			A[4] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	for (i = A[3] + 1; i <= 'z'; i++)
		if (memo[A[0] - 'a'][A[1] - 'a'][A[2] - 'a'][i - 'a'][A[4] - 'a'][A[5] - 'a'])
		{
			A[3] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	for (i = A[2] + 1; i <= 'z'; i++)
		if (memo[A[0] - 'a'][A[1] - 'a'][i - 'a'][A[3] - 'a'][A[4] - 'a'][A[5] - 'a'])
		{
			A[2] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	for (i = A[1] + 1; i <= 'z'; i++)
		if (memo[A[0] - 'a'][i - 'a'][A[2] - 'a'][A[3] - 'a'][A[4] - 'a'][A[5] - 'a'])
		{
			A[1] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	for (i = A[0] + 1; i <= 'z'; i++)
		if (memo[i - 'a'][A[1] - 'a'][A[2] - 'a'][A[3] - 'a'][A[4] - 'a'][A[5] - 'a'])
		{
			A[0] = i;
			printf("%s\n", A.c_str());
			return;
		}
 
	printf("0\n");
}
 
int main()
{
	int T, Q, t;
	string A;
	char type;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	for (t = 1; t <= T; t++)
	{
		scanf("%d", &Q);
 
		memset(memo, 0, sizeof(memo));
		printf("Test %d\n", t);
 
		while (Q--)
		{
			type = nextchar();
			getstring(A);
 
			if (type == 'W')
				insert(A);
			else
				query(A);
		}
	}
 
	return 0;
} 
