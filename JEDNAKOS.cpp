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
#include <map>
#include <limits.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#define INF 100000
 
using namespace std;
 
 
int memo[6001][5000];
string A, S;
int sum;
 
void init()
{
	char c;
	int counter=0;
 
	//c=fgetc(stdin);
	c=getchar_unlocked();
 
	while(c=='0')
		c=getchar_unlocked();
 
	while(c!='=')
	{
		if(c=='0')
			counter++;
		A.push_back(c);
		//c=fgetc(stdin);
		if(counter==3)
		{
			while(c=='0')
				c=getchar_unlocked();
			ungetc(c, stdin);
			counter=0;
		}
		c=getchar_unlocked();
	}
 
	//c=fgetc(stdin);
	c=getchar_unlocked();
 
	while(isdigit(c))
	{
		S.push_back(c);
		//c=fgetc(stdin);
		c=getchar_unlocked();
	}
 
	sum=atoi(S.c_str());
	
}
 
int solve(int sum, int pos)
{
	int i;
	int mmin=INF;
	char c;
	int curr=-1;
 
	if(memo[sum][pos]!=0)
		return memo[sum][pos];
 
	if(pos>A.length())
		return INF;
	
	if(atoi(A.c_str()+pos)==sum)
	{
		memo[sum][pos]=1;
		return 1;
	}
 
	for(i=pos+1; i<A.length() && curr<=sum; i++)
	{
		c=A[i];
		A[i]='\0';
		curr=atoi(A.c_str()+pos);
		A[i]=c;
		if(curr==0)
			continue;
		if(curr>sum)
			break;
		
 
		mmin=min(mmin, solve(sum-curr, i));
	}
 
	memo[sum][pos]=1+mmin;
	return 1+mmin;
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	init();
	
	printf("%d\n", solve(atoi(S.c_str()), 0)-1);
 
 
	return 0;
} 
