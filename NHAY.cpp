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
#include <limits.h>
using namespace std;
 
int T;
string needle, haystack;
int N;
int pos;
 
int main()
{
	char c;
 
	//freopen("input.txt","r",stdin);
	while(!feof(stdin))
	{
		c=fgetc(stdin);
		if(c==EOF)
			return 0;
		while(!isalpha(c))
		{
			c=fgetc(stdin);
			if(c==EOF)
				return 0;
		}
 
		ungetc(c, stdin);
 
		c=fgetc(stdin);
		while(isalpha(c))
		{
			needle.push_back(c);
			c=fgetc(stdin);
		}
 
		pos=0;
				
		c=fgetc(stdin);
		while(isalpha(c))
		{
			haystack.push_back(c);
			c=fgetc(stdin);
		}
 
		pos=haystack.find(needle, pos);
		while(pos>=0 && pos<haystack.size())
		{
			printf("%d\n", pos);
			pos=haystack.find(needle, pos+1);
		}
 
		if(c!=EOF)
			printf("\n");
		needle.clear();
		haystack.clear();
	}
 
	return 0;
} 
