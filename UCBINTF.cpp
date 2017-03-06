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
#include <iostream>
#include <string>
 
#define gc() getchar()
 
using namespace std;
 
int main()
{
	int C = 0, A = 0, i;
	string S;
 
	//freopen("input.txt", "r", stdin);
 
 
	cin >> S;
 
	for (i = 0; i < S.length(); i++)
	{
		if (i == 0 || S[i - 1] == '|')
			switch (S[i])
			{
			case 'C':
				C++;
				break;
			case 'G':
				C++;
				break;
			case 'F':
				C++;
				break;
			case 'A':
				A++;
				break;
			case 'E':
				A++;
				break;
			case 'D':
				A++;
				break;
			}
	}
 
	if (C > A)
		printf("C-dur");
	else if (C < A)
		printf("A-mol");
	else
	{
		if (S[S.length() - 1] == 'C' || S[S.length() - 1] == 'G' || S[S.length() - 1] == 'F')
			printf("C-dur");
		else
			printf("A-mol");
	}
 
	return 0;
} 
