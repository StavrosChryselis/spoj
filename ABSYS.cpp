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
#include <ctype.h>
 
#define gc() getchar_unlocked()
 
using namespace std;
 
inline int first()
{
	string A;
	char c;
 
	c = gc();
	while(isspace(c))
		c = gc();
 
	while(c!=' ')
	{
		if(isalpha(c))
		{
			while(c!=' ')
				c = gc();
			return -1;
		}
		A.push_back(c);
		c = gc();
	}
 
	return stoi(A);
}
 
inline int second()
{
	string A;
	char c;
 
	gc();
	gc();
	c = gc();
 
	while(c!=' ')
	{
		if(isalpha(c))
		{
			while(c!=' ')
				c = gc();
			return -1;
		}
		A.push_back(c);
		c = gc();
	}
 
	return stoi(A);
}
 
inline int third()
{
	string A;
	char c;
 
	gc();
	gc();
	c = gc();
 
	while(c!='\n' && c!=EOF)
	{
		if(isalpha(c))
		{
			while(c!='\n' && c!=EOF)
				c = gc();
			return -1;
		}
		A.push_back(c);
		c = gc();
	}
 
	return stoi(A);
}
 
int main()
{
	int T;
	int f, s, t;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
	{
		f = first();
		s = second();
		t = third();
 
		if(f == -1)
			f = t - s;
		if(s == -1)
			s = t - f;
		if(t == -1)
			t = f + s;
 
		printf("%d + %d = %d\n", f, s, t);
	}
 
	return 0;
} 
