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
 
using namespace std;
 
int main()
{
	int num;
	
	scanf("%d", &num);
	
	while(num!=42)
	{
		printf("%d\n", num);
		scanf("%d", &num);
	}
	
	return 0;
}
