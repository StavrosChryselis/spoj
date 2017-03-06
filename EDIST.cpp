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
#include <string.h>
#include <algorithm>
#include <string>
 
using namespace std;
 
int DP[3005][3005];
string A, B;
 
void init()
{
	char c;
	
	A.clear();
	B.clear();
 
	c=fgetc(stdin);
	while(!isalpha(c))
		c=fgetc(stdin);
 
	A.push_back(c);
 
	c=fgetc(stdin);
	while(isalpha(c))
	{
		A.push_back(c);
		c=fgetc(stdin);
	}
 
	c=fgetc(stdin);
	while(!isalpha(c))
		c=fgetc(stdin);
 
	B.push_back(c);
 
	c=fgetc(stdin);
	while(isalpha(c))
	{
		B.push_back(c);
		c=fgetc(stdin);
	}
 
}
 
void clear()
{
	int i, j;
 
	for(i=0; i<=A.length(); i++)
		for(j=0; j<=B.length(); j++)
			DP[i][j]=0;
}
 
int main()
{
	int T, i, j;
 
	//freopen("input.txt","r",stdin);
	
	scanf("%d", &T);
 
	while(T--)
	{
		init();
		clear();
 
		for(i=1; i<=A.length(); i++)
			DP[i][0]=i;
 
		for(j=1; j<=B.length(); j++)
			DP[0][j]=j;
 
		for(j=1; j<=B.length(); j++)
			for(i=1; i<=A.length(); i++)
			{
				if(A[i-1]==B[j-1])
					DP[i][j]=DP[i-1][j-1];
				else
					DP[i][j]= min(DP[i-1][j] + 1, min(DP[i][j-1] + 1, DP[i-1][j-1] +1));
			}
 
	/*	for(j=0; j<=B.length(); j++)
		{
			for(i=0; i<=A.length(); i++)
				printf("%d ", DP[i][j]);
			printf("\n");
		}*/
		printf("%d\n", DP[A.length()][B.length()]);
	}
 
	return 0;
} 
