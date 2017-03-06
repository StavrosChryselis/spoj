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
#define MAXN 99999999
 
using namespace std;
 
bool one[100000000];
bool three[100000000];
bool nine[100000000];
 
inline int digit_sum(int num)
{
	int sum = 0;
 
	while(num)
	{
		sum += num % 10;
		num /= 10;
	}
 
	return sum;
}
 
inline pair<int, int> solve(int num)
{
	while(1)
	{
		if(one[num])
			return make_pair(1, num);
		if(three[num])
			return make_pair(3, num);
		if(nine[num])
			return make_pair(9, num);
 
		num += digit_sum(num);
	}
}
 
int main()
{
	int num = 0, add = 1, T, n;
	pair<int, int> ans;
 
	while(num + add <= MAXN)
	{
		num += add;
		one[num] = 1;
		add = digit_sum(num);
	}
 
	num = 0;
	add = 3;
 
	while(num + add <= MAXN)
	{
		num += add;
		three[num] = 1;
		add = digit_sum(num);
	}
 
	num = 0;
	add = 9;
 
	while(num + add <= MAXN)
	{
		num += add;
		nine[num] = 1;
		add = digit_sum(num);
	}
 
	scanf("%d", &T);
 
	while(T--)
	{
		scanf("%d", &n);
		ans = solve(n);
		printf("%d %d\n", ans.first, ans.second);
	}
 
	return 0;
} 
