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

#include <iostream>
#include <cmath>
#include <cstring>
 
#define ll long long
#define gc getchar_unlocked
using namespace std;
 
inline int FAST_IO()
{
	char ch;
	int val = 0;
	ch = gc();
	while (isspace(ch) && ch != EOF)
		ch = gc();
	val = 0;
	while (isdigit(ch))
	{
		val = (val * 10) + (ch - '0');
		ch = gc();
	}
	return val;
}
 
inline ll solve(int num)
{
	double curr = num / 4.0;
	ll rval = 0;
	int i = 2;
 
	while (round(curr))
	{
		rval += round(curr) * i * i * i;
		i++;
		curr /= 2.0;
	}
 
	return rval;
}
 
int main()
{
//	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(0);
 
	int T, num;
 
	T = FAST_IO();
 
	while (T--)
	{
		num = FAST_IO();
		cout << solve(num) << "\n";
	}
 
	return 0;
} 
