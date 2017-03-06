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
#include <string>
#define N 10000
 
using namespace std;
 
bool sieve[10000];
 
void calc_primes()
{
	int i, j;
 
	for(i = 2; i < N; i++)
		if(!sieve[i])
			for(j = i + i; j < N; j+=i)
				sieve[j] = 1;
}
 
int solve(int start, int target)
{
	deque<pair<string, int> > Q;
	pair<string, int> curr;
	vector<bool> V(N);
	int i, tempn;
	string temp;
 
	if(start == target)
		return 0;
 
	curr = make_pair(to_string(start), 0);
	Q.push_back(curr);
	
	while(!Q.empty())
	{
		curr = Q.front();
		Q.pop_front();
 
		for(i=1; i<=9; i++)
		{
			temp = curr.first;
			temp[0] = i + '0';
			tempn = stoi(temp);
 
			if(!sieve[tempn] && !V[tempn])
			{
				if(tempn == target)
					return curr.second + 1;
				Q.push_back(make_pair(temp, curr.second + 1));
				V[tempn] = 1;
			}
 
			temp = curr.first;
			temp[1] = i + '0';
			tempn = stoi(temp);
 
			if(!sieve[tempn] && !V[tempn])
			{
				if(tempn == target)
					return curr.second + 1;
				Q.push_back(make_pair(temp, curr.second + 1));
				V[tempn] = 1;
			}
 
			temp = curr.first;
			temp[2] = i + '0';
			tempn = stoi(temp);
 
			if(!sieve[tempn] && !V[tempn])
			{
				if(tempn == target)
					return curr.second + 1;
				Q.push_back(make_pair(temp, curr.second + 1));
				V[tempn] = 1;
			}
 
			temp = curr.first;
			temp[3] = i + '0';
			tempn = stoi(temp);
 
			if(!sieve[tempn] && !V[tempn])
			{
				if(tempn == target)
					return curr.second + 1;
				Q.push_back(make_pair(temp, curr.second + 1));
				V[tempn] = 1;
			}
		}
 
		temp = curr.first;
		temp[1] = '0';
		tempn = stoi(temp);
 
		if(!sieve[tempn] && !V[tempn])
		{
			if(tempn == target)
					return curr.second + 1;
			Q.push_back(make_pair(temp, curr.second + 1));
			V[tempn] = 1;
		}
 
		temp = curr.first;
		temp[2] = '0';
		tempn = stoi(temp);
 
		if(!sieve[tempn] && !V[tempn])
		{
			if(tempn == target)
					return curr.second + 1;
			Q.push_back(make_pair(temp, curr.second + 1));
			V[tempn] = 1;
		}
 
		temp = curr.first;
		temp[3] = '0';
		tempn = stoi(temp);
 
		if(!sieve[tempn] && !V[tempn])
		{
			if(tempn == target)
					return curr.second + 1;
			Q.push_back(make_pair(temp, curr.second + 1));
			V[tempn] = 1;
		}
	}
 
	return -1;
}
 
int main()
{
	int T, temp, f, s;
 
	//freopen("input.txt","r",stdin);
 
	calc_primes();
	scanf("%d", &T);
 
	while(T--)
	{
		scanf("%d %d", &f, &s);
		temp = solve(f, s);
 
		if(temp!=-1)
			printf("%d\n", temp);
		else
			printf("Impossible\n");
	}
 
	return 0;
} 
