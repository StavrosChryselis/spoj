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
 
using namespace std;
 
deque<int> road, side;
int N;
 
bool init()
{
	int i, num;
 
	scanf("%d", &N);
 
	if(N==0)
		return 0;
 
	road.clear();
	side.clear();
 
	for(i=0; i<N; i++)
	{
		scanf("%d", &num);
		road.push_front(num);
	}
 
	return 1;
}
 
bool can_find(int curr)
{
	if(road.empty())
	{
		if(side.back()!=curr)
			return 0;
 
		side.pop_back();
		return 1;
	}
 
 
	if(road.back()==curr)
	{
		road.pop_back();
		return 1;
	}
 
	if(side.empty())
	{
		while(road.back()!=curr && !road.empty())
		{
			side.push_back(road.back());
			road.pop_back();
		}
 
		if(road.empty())
			return 0;
 
		road.pop_back();
		return 1;
	}
	
	if(side.back()==curr)
	{
		side.pop_back();
		return 1;
	}
 
	while(road.back()!=curr && !road.empty())
	{
		side.push_back(road.back());
		road.pop_back();
	}
 
	if(road.empty())
		return 0;
 
	road.pop_back();
	return 1;
}
 
void solve()
{
	int i;
 
	for(i=1; i<=N; i++)
		if(!can_find(i))
		{
			printf("no\n");
			return;
		}
	printf("yes\n");
}
 
int main()
{
	//freopen("input.txt","r",stdin);
 
	while(init())
		solve();
 
	return 0;
} 
