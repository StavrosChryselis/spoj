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
#include <string>
#include <iostream>
 
using namespace std;
 
int A[] = { 1, 2, 3 ,4, 5, 6, 7, 8, 9 };
string S;
int N;
 
inline void init()
{
	sort(A, A + 9);
 
	cin >> S;
	N = S.length();
}
 
inline bool check()
{
	int i;
 
	for (i = 1; i <= N; i++)
	{
		switch (S[i - 1])
		{
		case 'A':
			if (A[i - 1] > A[i])
				return 0;
			break;
		case 'B':
			if (A[i - 1] < A[i])
				return 0;
			break;
		}
	}
 
	return 1;
}
 
inline void solve()
{
	do
	{
		if (check())
			return;
	} while (next_permutation(A, A + N + 1));
}
 
int main()
{
	int T, i;
 
	//freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		solve();
 
		for (i = 0; i <= N; i++)
			printf("%d", A[i]);
		printf("\n");
	}
 
	return 0;
} 
