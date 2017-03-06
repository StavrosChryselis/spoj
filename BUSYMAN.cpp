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
#include <vector>
 
using namespace std;
 
int N;
vector< pair<int,int> > A;
 
void init()
{
	int i;
	pair<int, int> temp;
 
	scanf("%d", &N);
	A.clear();
 
	for(i=0; i<N; i++)
	{
		scanf("%d %d", &temp.second, &temp.first);
		A.push_back(temp);
	}
 
	sort(A.begin(), A.end());
}
 
int main()
{
	int T, i;
	int counter=1;
	pair<int, int> curr;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
	{
		counter=1;
		init();
 
		curr=*A.begin();
 
		for(i=1; i<A.size(); i++)
			if(A[i].second>=curr.first)
			{
				curr=A[i];
				counter++;
			}
 
		printf("%d\n", counter);
	}
	return 0;
} 
