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
#include <string>
#include <string.h>
 
using namespace std;
 
unordered_map<string, int> hashh;
int countt[20001];
int N, L;
 
bool init()
{
	int i, j;
	char c;
	string A;
 
	scanf("%d %d", &N, &L);
	if(N==0 && L==0)
		return 0;
 
	A.resize(L+1);
	hashh.clear();
	memset(countt, 0, sizeof(countt));
 
	c=fgetc(stdin);
	while(!isalpha(c))
		c=fgetc(stdin);
 
	ungetc(c,stdin);
 
	for(i=0; i<N; i++)
	{
		for(j=0; j<L; j++)
			A[j]=fgetc(stdin);
 
		if(hashh.find(A)==hashh.end())
			hashh[A]=1;
		else
			hashh[A]++;
 
		if(i!=N-1)
		{
			c=fgetc(stdin);
			while(!isalpha(c))
				c=fgetc(stdin);
			ungetc(c,stdin);
		}
	}
 
	return 1;
}
 
int main()
{
	//freopen("input.txt","r",stdin);
 
	while(init())
	{
		for(unordered_map<string, int>::iterator ii=hashh.begin(); ii!=hashh.end(); ii++)
			countt[ii->second]++;
 
		for(int i=1; i<=N; i++)
			printf("%d\n", countt[i]);
	}
 
	return 0;
} 
