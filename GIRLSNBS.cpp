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
#include <math.h>
#include <algorithm>
 
using namespace std;
 
int main()
{
	float G, B;
 
	scanf("%f %f", &G, &B);
 
	while(G!=-1 && B!=-1)
	{
		printf("%d\n", (int)ceil(max(G,B)/(min(G,B)+1)));
		scanf("%f %f", &G, &B);
	}
 
	return 0;
} 
