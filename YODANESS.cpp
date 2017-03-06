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
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
 
#define gc() getchar_unlocked()
 
using namespace std;
 
unsigned long long tree[30007];
unordered_map<string, int> MAP;
vector<string> YODA;
int N;
 
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
 
inline void update(int pos, int val)
{
	for (; pos <= N; pos += pos & (-pos))
		tree[pos] += val;
}
 
inline unsigned long long query(int pos)
{
	unsigned long long sum = 0;
 
	for (; pos > 0; pos -= pos & (-pos))
		sum += tree[pos];
 
	return sum;
}
 
void init()
{
	int i;
	string A;
 
	YODA.clear();
	memset(tree, 0, sizeof(tree));
 
	scanf("%d", &N);
 
	for (i = 0; i<N; i++)
	{
		getstring(A);
		YODA.push_back(A);
	}
 
	for (i = 0; i<N; i++)
	{
		getstring(A);
		MAP[A] = i + 1;
	}
}
 
int main()
{
	int i, T;
	unsigned long long sum = 0;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		sum = 0;
		for (i = N - 1; i >= 0; i--)
		{
			update(MAP[YODA[i]] + 1, 1);
			sum += query(MAP[YODA[i]]);
		}
 
		printf("%llu\n", sum);
	}
 
	return 0;
} 
