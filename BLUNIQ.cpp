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
#include <set>
#include <ctype.h>
#define gc() getchar_unlocked()
 
using namespace std;
 
set< pair<int, int> > S; //1 = begin, 3 = end, 2 = insert
 
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
 
inline void init()
{
	S.insert(make_pair(0, 3));
	S.insert(make_pair(2000000000, 1));
}
 
inline int add(int num)
{
	set< pair<int, int> >::iterator ii;
	int ans;
 
	ii = S.insert(make_pair(num, 2)).first;
 
	if (prev(ii)->second == 1 && next(ii)->second == 3)
	{
		ans = next(ii)->first;
		if (next(next(ii))->first == next(ii)->first + 1)
		{
			S.erase(next(next(ii)));
			S.erase(next(ii));
		}
 
		else
		{
			S.insert(next(next(ii)), make_pair(next(ii)->first + 1, 3));
			S.erase(next(ii));
		}
		S.erase(ii);
		return ans;
	}
 
	if (prev(ii)->second == 3 && next(ii)->second == 1)
	{
		ans = num;
		S.insert(ii, make_pair(num, 1));
		if (next(ii)->first == num + 1)
			S.erase(next(ii));
		else
			S.insert(next(ii), make_pair(num + 1, 3));
		S.erase(ii);
		return ans;
	}
}
 
inline void rem(int num)
{
	set< pair<int, int> >::iterator ii;
 
	ii = S.lower_bound(make_pair(num, 2));
	ii = prev(ii);
	if (ii->first == num)
	{
		if (next(ii)->first == num + 1)
		{
			S.erase(next(ii));
			S.erase(ii);
 
			return;
		}
 
		else
		{
			S.insert(next(ii), make_pair(num + 1, 1));
			S.erase(ii);
 
			return;
		}
	}
 
	else
	{
		S.insert(next(ii), make_pair(num + 1, 1));
		S.insert(next(ii), make_pair(num, 3));
	}
}
 
int main()
{
	int num, type, T;
 
	init();
 
	//scanf("%d", &T);
	T = FAST_IO();
	while (T--)
	{
 
		//scanf("%d %d", &type, &num);
		type = FAST_IO();
		num = FAST_IO();
 
		if (type == 1)
			printf("%d\n", add(num));
		else
			rem(num);
	}
 
	return 0;
} 
