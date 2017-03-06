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
#include <algorithm>
#define gc() getchar_unlocked()
 
using namespace std;
 
int one, eight, zero, seven;
 
int main()
{
	char c;
 
	//freopen("input.txt","r",stdin);
 
	c = gc();
	while(c != EOF)
	{
		switch(c)
		{
			case '1':
				one++;
				break;
			case '8':
				if(one == 0)
					break;
				eight = max(eight, one) + 1;
				break;
			case '0':
				if(eight == 0)
					break;
				zero = max(zero, eight) + 1;
				break;
			case '7':
				if(zero == 0)
					break;
				seven = max(seven, zero) + 1;
				break;
		}
 
		c = gc();
	}
 
	printf("%d\n", seven);
 
	return 0;
} 
