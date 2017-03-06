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
 
int main()
{
	int num;
	int res;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &num);
	while(num!=0)
	{
		res=log((float)num)/log((float)2) -1;
		printf("%d\n", res+1);
		scanf("%d", &num);
	}
 
 
	return 0;
} 
