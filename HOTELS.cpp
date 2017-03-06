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
#include <deque>
#include <algorithm>
 
using namespace std;
 
deque<int> A;
int N, M;
 
int main()
{
	int i, num, MAX = 0, sum = 0;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d %d", &N, &M);
 
	for(i=0; i<N; i++)
	{
		scanf("%d", &num);
	
		if(num == M)
		{
			printf("%d\n", M);
			return 0;
		}
 
		if(num > M)
		{
			A.clear();
			sum = 0;
			continue;
		}
 
		if(sum + num <= M)
		{
			A.push_back(num);
			sum += num;
			MAX=max(MAX, sum);
			continue;
		}
		
		while(sum + num > M)
		{
			sum -= A.front();
			A.pop_front();
		}
 
		sum += num;
		A.push_back(num);
		MAX = max(MAX, sum);
	}
 
	printf("%d\n", MAX);
 
	return 0;
} 
