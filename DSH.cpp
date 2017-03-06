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

#include <string>
#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int val[] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 20, 21, 22, 23, 24, 25, 26, 18, 19, 20, 21, 22, 23 };
 
int main()
{
	string S;
	int i;
 
//	freopen("input.txt", "r", stdin);
 
	while (cin >> S)
	{
		int c = 0;
 
		for (i = 0; i < S.length(); i++)
		{
			printf("%d ", val[S[i] - 'a']);
			if (val[S[i] - 'a'] > 23)
				c++;
		}
		putchar('\n');
 
		if (c)
			printf("%d\n", c);
		else
			printf("no one.\n");
	}
 
	return 0;
} 
