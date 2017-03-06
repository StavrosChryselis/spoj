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
 
deque< pair<int, int> > WORK;
bool V[1000001];
 
int main()
{
	int f, s, g, u, d;
	pair<int, int> curr;
 
	//freopen("input.txt","r",stdin);
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
 
	WORK.push_back(make_pair(s, 0));
 
	if(s==g)
	{
		printf("0\n");
		return 0;
	}
 
	while(!WORK.empty())
	{
		curr=WORK.front();
		WORK.pop_front();
 
		if(V[curr.first])
			continue;
 
		V[curr.first]=1;
 
		if(curr.first + u == g)
		{
			printf("%d\n", curr.second+1);
			return 0;
		}
 
		if(curr.first - d == g)
		{
			printf("%d\n", curr.second+1);
			return 0;
		}
 
 
		if(curr.first + u <= f && !V[curr.first+u])
			WORK.push_back(make_pair(curr.first+u, curr.second+1));
 
		if(curr.first - d >= 1 && !V[curr.first-d])
			WORK.push_back(make_pair(curr.first-d, curr.second+1));
	}
 
	printf("use the stairs\n");
 
	return 0;
} 
