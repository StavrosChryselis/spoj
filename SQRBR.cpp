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
#include <unordered_map>
#include <string.h>
 
using namespace std;
 
unordered_map<int, unordered_map<int, int> > memo;
 
 
bool A[40];
int N;
 
int f(int open, int pos)
{
	if(memo.find(open)!=memo.end() && memo[open].find(pos)!=memo[open].end())
		return memo[open][pos];
 
	if(pos>N)
	{
		if(open==0)
			return 1;
		return 0;
	}
	if(A[pos])
		return f(open+1, pos+1);
 
	memo[open][pos]=0;
	memo[open][pos]=f(open+1, pos+1);
 
	if(open>0)
		memo[open][pos]+=f(open-1, pos+1);
 
	return memo[open][pos];
}
 
inline void init()
{
	int i, K, num;
 
	memo.clear();
	memset(A, 0, sizeof(A));
 
	scanf("%d %d", &N, &K);
	N*=2;
 
	for(i=0; i<K; i++)
	{
		scanf("%d", &num);
		A[num]=1;
	}
 
	A[1]=1;
}
 
int main()
{
	int i, T, j;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
	{
		init();
 
		printf("%d\n", f(0, 1));
	}
 
	return 0;
} 
