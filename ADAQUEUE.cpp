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
#include <string>
#include <ctype.h>
 
#define gc() getchar()
using namespace std;
 
inline void getstring(string &A)
{
	char c = gc();
 
	A.clear();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}
 
deque<int> Q;
bool rev;
 
inline void tofront(int num)
{
	if (rev)
		Q.push_back(num);
	else
		Q.push_front(num);
}
 
inline void toback(int num)
{
	if (rev)
		Q.push_front(num);
	else
		Q.push_back(num);
}
 
inline void front()
{
	if (Q.empty())
		printf("No job for Ada?\n");
	else
	{
		if (rev)
		{
			printf("%d\n", Q.back());
			Q.pop_back();
		}
 
		else
		{
			printf("%d\n", Q.front());
			Q.pop_front();
		}
	}
}
 
inline void back()
{
	if (Q.empty())
		printf("No job for Ada?\n");
	else
	{
		if (rev)
		{
			printf("%d\n", Q.front());
			Q.pop_front();
		}
 
		else
		{
			printf("%d\n", Q.back());
			Q.pop_back();
		}
	}
}
 
inline void command()
{
	string S;
	int num;
 
	getstring(S);
 
	if (S == "toFront")
	{
		scanf("%d", &num);
		tofront(num);
	}
 
	else if (S == "front")
		front();
 
	else if (S == "back")
		back();
 
	else if (S == "push_back")
	{
		scanf("%d", &num);
		toback(num);
	}
 
	else
		rev = !rev;
}
 
int main()
{
	int N;
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &N);
 
	while (N--)
		command();
 
	return 0;
} 
