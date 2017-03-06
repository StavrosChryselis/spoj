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
#include <deque>
#include <vector>
#define gc() getchar_unlocked();
#define N 8
 
using namespace std;
 
int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
pair<int, int> start, finish;
 
inline bool in_range(pair<int, int> pos)
{
	if(pos.first <1 || pos.first > 8 || pos.second < 1 || pos.second > 8)
		return 0;
	return 1;
}
 
inline void init()
{
	char a, b, c, d;
 
	a=gc();
	b=gc();
	gc();
	c=gc();
	d=gc();
	gc();
 
	start.first = b-'0';
	start.second = a - 'a' + 1;
 
	finish.first = d - '0';
	finish.second = c - 'a' + 1;
	
}
 
int solve()
{
	deque< pair<int, pair< int, int > > > Q;
	pair<int, pair< int, int > > curr, temp;
	int i;
 
	Q.push_back(make_pair(0, start));
 
	while(!Q.empty())
	{
		curr = Q.front();
		Q.pop_front();
 
		if(curr.second == finish)
			return curr.first;
		if(!in_range(curr.second))
			continue;
 
		for(i=0; i<8; i++)
		{
			temp = curr;
			temp.first++;
			temp.second.first += dx[i];
			temp.second.second += dy[i];
			if(in_range(temp.second))
				Q.push_back(temp);
		}
	}
 
	return 1000;
}
 
int main()
{
	int T;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d\n", &T);
	while(T--)
	{
		init();
		printf("%d\n", solve());
	}
	return 0;
} 
