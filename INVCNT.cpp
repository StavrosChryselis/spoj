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
#include <iostream>
 
using namespace std;
 
unsigned long long tree[200007];
int A[400007];
unordered_map<int, int> map, reverse_map;
int N;
 
inline void update(int pos, int val)
{
	for( ; pos <= 200006; pos += pos & (-pos))
		tree[pos] += val;
}
 
inline unsigned long long query(int pos)
{
	unsigned long long sum = 0;
 
	for( ; pos > 0; pos -= pos & (-pos))
		sum += tree[pos];
 
	return sum;
}
 
void init()
{
	int i, counter;
	int temp[200007];
 
	memset(tree, 0, sizeof(tree));
 
	scanf("%d", &N);
 
	for(i=0; i<N; i++)
	{
		scanf("%d", &A[i]);
		temp[i]=A[i];
	}
 
	sort(temp, temp + N);
 
	counter=2;
	map[temp[0]] = 1;
	reverse_map[1] = temp[0];
 
	for(i=1; i<N; i++)
		if(temp[i] != temp[i-1])
		{
			map[temp[i]] = counter++;
			reverse_map[counter-1] = temp[i];
		}
}
 
int main()
{
	int i, T;
	unsigned long long sum = 0;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
	{
		init();
		sum=0;
		for(i = N-1; i >= 0; i--)
		{
			update(map[A[i]] + 1, 1);
			sum += query(map[A[i]]);
		}
 
		printf("%llu\n", sum);
	}
 
	return 0;
} 
