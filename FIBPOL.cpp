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

#include <iostream>
#include <math.h>
 
using namespace std;
 
inline bool solve(long long num)
{
	long long temp;
	double res;
	
	res = num;
	
	res = sqrt((res + 1) * (res + 1) + 4 *res * res);
	temp = res;
	
	if(temp == res)
		return 1;
	return 0;
}
 
int main() 
{
	int T;
	long long num;
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%lld", &num);
		printf("%d\n", solve(num));
	}
	return 0;
} 
