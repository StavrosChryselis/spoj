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
#include <math.h>
#include <algorithm>
 
using namespace std;
 
int memo[1010][1010];
int a[1010], b[1010];
int N;
 
unsigned int f(int pos, int h)
{
	if(pos==N)
		return 0;
 
	if(memo[pos][h]!=0)
		return memo[pos][h];
 
	if(pos==0)
		memo[pos][h]=max(b[pos]+f(pos+1, a[pos]),a[pos]+f(pos+1, b[pos]));
	else
		memo[pos][h]=max(abs(a[pos]-h)+b[pos]+f(pos+1, a[pos]), abs(b[pos]-h)+a[pos]+f(pos+1, b[pos]));
	return memo[pos][h];
}
 
int main()
{
	int i;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &N);
 
	for(i=0; i<N; i++)
		scanf("%d %d", &a[i], &b[i]);
 
	printf("%d\n", f(0, 0));
 
	return 0;
} 
