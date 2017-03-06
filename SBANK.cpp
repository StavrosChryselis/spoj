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
#include <string>
 
using namespace std;
 
map<string,int> all;
 
int main()
{
	int t, i, N;
	map<string, int>::iterator ii;
	char s[32];
	char c;
	string str;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &t);
 
	while(t--)
	{
		all.clear();
 
		scanf("%d", &N);
 
		c=fgetc(stdin);
		while(!isdigit(c))
			c=fgetc(stdin);
		ungetc(c, stdin);
 
		for(i=0; i<N; i++)
		{
			fgets(s, 32, stdin);
			c=fgetc(stdin);
			while(!isdigit(c) &&c!=EOF)
				c=fgetc(stdin);
			ungetc(c, stdin);
			str=s;
			ii=all.find(str);
			if(ii!=all.end())
				ii->second++;
			else
				all[str]=1;
		}
 
		for(ii=all.begin(); ii!=all.end(); ii++)
			printf("%s %d\n", ii->first.c_str(), ii->second);
		printf("\n");
	}
 
 
 
	return 0;
} 
