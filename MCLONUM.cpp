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
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#define gc() getchar_unlocked()
 
using namespace std;
 
string ans;
string A;
string B;
bool mark[64];
 
inline string read_string()
{
	char c;
	string S;
 
	c = gc();
 
	while(isspace(c))
		c = gc();
 
	S.push_back(c);
 
	c = gc();
 
	while(!isspace(c) && c != EOF)
	{
		S.push_back(c);
		c = gc();
	}
 
	return S;
}
 
inline void init()
{
	A = read_string();
	B = read_string();
	sort(B.begin(), B.end());
}
 
inline bool bigger(int pos)
{
	int i, j;
 
	if(pos == B.size() - 1)
	{
		for(i=0; i<B.size(); i++)
			if(!mark[i] && B[i] >= A[pos])
			{
				ans.push_back(B[i]);
				return 1;
			}
 
		return 0;
	}
 
	for(i=0; i<B.size(); i++)
	{
		if(!mark[i])
		{
			if(B[i] == A[pos])
			{
				ans.push_back(B[i]);
				mark[i] = 1;
 
				if(bigger(pos+1))
					return 1;
 
				ans.pop_back();
				mark[i] = 0;
			}
 
			else if(B[i] > A[pos])
			{
				mark[i] = 1;
				ans.push_back(B[i]);
				for(j=0; j<B.size(); j++)
					if(!mark[j])
						ans.push_back(B[j]);
 
				return 1;
			}
		}
	}
 
	return 0;
}
 
inline bool smaller(int pos)
{
	int i, j;
 
	if(pos == B.size() - 1)
	{
		for(i=0; i<B.size(); i++)
			if(!mark[i] && B[i] < A[pos])
			{
				ans.push_back(B[i]);
				return 1;
			}
 
		return 0;
	}
 
	for(i=0; i<B.size(); i++)
	{
		if(!mark[i])
		{
			if(B[i] == A[pos])
			{
				ans.push_back(B[i]);
				mark[i] = 1;
 
				if(smaller(pos+1))
					return 1;
 
				ans.pop_back();
				mark[i] = 0;
			}
 
			else if(B[i] < A[pos])
			{
				if(pos == 0 && B[i] == '0')
					return 0;
				mark[i] = 1;
				ans.push_back(B[i]);
				for(j=0; j<B.size(); j++)
					if(!mark[j])
						ans.push_back(B[j]);
 
				return 1;
			}
		}
	}
 
	return 0;
}
int main()
{
	//freopen("input.txt","r",stdin);
 
	init();
 
 
	if(bigger(0))
		printf("%s\n", ans.c_str());
	else
		printf("0\n");
 
	memset(mark, 0, sizeof(mark));
	ans.clear();
	reverse(B.begin(), B.end());
 
	if(smaller(0))
		printf("%s\n", ans.c_str());
	else
		printf("0\n");
 
	return 0;
} 
