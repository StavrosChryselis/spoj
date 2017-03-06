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
#include <unordered_map>
 
using namespace std;
 
int memo[500007];
 
inline void pre()
{
	int i, prev = 0, curr;
	unordered_map<int, bool> A;
	
	A[0] = 1;
	
	for(i = 1; i<= 500000; i++)
	{
		curr = prev - i;
		if(curr < 0 || A.find(curr) != A.end())
			curr = prev + i;
		
		A[curr] = 1;
		memo[i] = curr;
		prev = curr;
	}
}
 
int main()
{
	int num;
	
	pre();
	scanf("%d", &num);
	
	while(num != -1)
	{
		printf("%d\n", memo[num]);
		scanf("%d", &num);
	}
	
	return 0;
} 
