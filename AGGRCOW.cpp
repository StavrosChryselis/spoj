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
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> A;
int N, M;
 
inline bool check(int x, int m)
{
	int i=1;
	int curr=A[0];
	m--;
	while(m>0)
	{
		if(A[i]-curr>=x)
		{
			m--;
			curr=A[i];
		}
		i++;
		if(m>0 && i>=N)
			return 0;
	}
 
	return 1;
}
 
void init()
{
	int i, num;
 
	A.clear();
 
	scanf("%d %d", &N, &M);
 
	for(i=0; i<N; i++)
	{
		scanf("%d", &num);
		A.push_back(num);
	}
 
	sort(A.begin(), A.end());
 
	num=A[A.size()-1];
}
 
 
int main()
{
	int T;
	int begin, end, mid;
 
	//freopen("input.txt","r",stdin);
	scanf("%d", &T);
 
	while(T--)
	{
		init();
		begin=1;
		end=A[N-1]-A[0];
		while(end!=begin+1)
		{
			mid=(begin+end)/2;
			if(check(mid, M))
				begin=mid;
			else
				end=mid;
		}
 
		printf("%d\n", begin);
 
		
	}
 
	return 0;
} 
