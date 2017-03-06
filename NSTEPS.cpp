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
	int N, i;
	int x, y;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &N);
	
	for(i=0; i<N; i++)
	{
		scanf("%d %d", &x, &y);
 
		if(x>10000 || y>10000 || x<y)
			printf("No Number\n");
 
		else if(x-y==0 || x-y==2)
		{
			if(x%2==0)
				printf("%d\n", x+y);
			else
				printf("%d\n", x+y-1);
		}
 
		else
			printf("No Number\n");
	}
 
	return 0;
} 
