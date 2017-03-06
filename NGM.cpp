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
 
int main()
{
	int num, t;
 
	scanf("%d", &num);
 
	t = num % 10;
 
	if (t == 0)
		printf("2\n");
	else
		printf("1\n%d\n", t);
 
	return 0;
} 
