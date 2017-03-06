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
	int T, n, p;
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d %d", &n, &p);
		
		if(p)
			printf("Pagfloyd wins.\n");
		else
			printf("Airborne wins.\n");
	}
	
	return 0;
} 
