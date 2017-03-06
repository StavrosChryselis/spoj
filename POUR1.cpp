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
#include <deque>
#include <algorithm>
 
using namespace std;
 
unordered_map<int, unordered_map<int, bool> > memo;
int a, b, c;
 
long long solve()
{
	deque< pair<long long, pair<int, int> > > Q;
	pair<long long, pair<int, int> > curr;
 
	memo.clear();
	Q.push_back(make_pair(0, make_pair(0, 0)));
 
	while(!Q.empty())
	{
		curr=Q.front();
		Q.pop_front();
 
		if(curr.second.first==c || curr.second.second==c)
			return curr.first;
 
		if(memo.find(curr.second.first)!=memo.end() && memo[curr.second.first].find(curr.second.second)!=memo[curr.second.first].end())
			continue;
		else
			memo[curr.second.first][curr.second.second]=1;
 
		Q.push_back(make_pair(curr.first+1, make_pair(0, curr.second.second)));
		Q.push_back(make_pair(curr.first+1, make_pair(curr.second.first, 0)));
 
		if(curr.second.first!=a)
			Q.push_back(make_pair(curr.first+1, make_pair(a, curr.second.second)));
		if(curr.second.second!=b)
			Q.push_back(make_pair(curr.first+1, make_pair(curr.second.first, b)));
 
		if(curr.second.first!=0 && curr.second.second!=b)
			Q.push_back(make_pair(curr.first+1, make_pair(curr.second.first - min(curr.second.first, b-curr.second.second), curr.second.second +  min(curr.second.first, b-curr.second.second))));
 
		if(curr.second.second!=0 && curr.second.first!=a)
			Q.push_back(make_pair(curr.first+1, make_pair(curr.second.first + min(a-curr.second.first, curr.second.second), curr.second.second - min(a-curr.second.first, curr.second.second))));
	}
 
	return -1;
}
 
int main()
{
	int T;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
	{
		scanf("%d %d %d", &a, &b, &c);
		printf("%lld\n", solve());
	}
 
	return 0;
} 
