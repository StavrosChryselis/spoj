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
#include <limits.h>
#include <string.h>
#include <algorithm>
 
#define min(a,b) (a<b)?a:b;
 
int unopen[30007*4];
int unclose[30007*4];
char str[30007];
int N;
 
void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
 
void inittree(int index, int a, int b)
{
	int newmatches;
 
	if(a==b)
	{
		if(str[a-1]=='(')
		{
			unopen[index]=1;
			unclose[index]=0;
		}
 
		else
		{
			unopen[index]=0;
			unclose[index]=1;
		}
		return;
	}
 
	inittree(index*2, a, (a+b)/2);
	inittree(index*2+1, (a+b)/2+1, b);
	
	newmatches=min(unopen[index*2], unclose[index*2+1]);
	unopen[index]=unopen[index*2]+unopen[index*2+1]-newmatches;
	unclose[index]=unclose[index*2]+unclose[index*2+1]-newmatches;
 
}
 
void update(int index, int a, int b, int pos)
{
	int newmatches;
 
	if(a==b && a==pos)
	{
		swap(&unopen[index], &unclose[index]);
		return;
	}
 
	if(pos<=(a+b)/2)
		update(index*2, a, (a+b)/2, pos);
 
	else
		update(index*2+1, (a+b)/2+1, b, pos);
 
	newmatches=min(unopen[index*2], unclose[index*2+1]);
	unopen[index]=unopen[index*2]+unopen[index*2+1]-newmatches;
	unclose[index]=unclose[index*2]+unclose[index*2+1]-newmatches;
}
	
 
	
void init()
{
	scanf("%d", &N);
	scanf("%s", str);
	
	memset(unopen, 0, sizeof(unopen));
	memset(unclose, 0, sizeof(unclose));
 
	inittree(1, 1, N);
}
 
int main()
{
	int i, j;
	int P;
	int num;
 
	//freopen("input.txt","r", stdin);
 
	for(i=1; i<=10; i++)
	{
		init();
		printf("Test %d:\n", i);
 
		scanf("%d", &P);
		for(j=0; j<P; j++)
		{
			scanf("%d", &num);
			if(num==0)
			{
				if(unopen[1]==0 && unclose[1]==0)
					printf("YES\n");
				else
					printf("NO\n");
			}
 
			else
				update(1, 1, N, num);
		}
	}
 
	return 0;
} 
