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
#include <string.h>
 
char str[50000];
unsigned long long DP[50000];
 
bool init()
{
	scanf("%s", str);
 
	if(strcmp(str, "0")==0)
		return 0;
 
	memset(DP, 0, sizeof(DP));
 
	return 1;
}
 
 
inline bool valid(int i, int j)
{
	if(i==j)
	{
		if(str[i]=='0')
			return 0;
		return 1;
	}
 
	if(str[i]=='0')
		return 0;
 
	if((str[i]-'0')*10 + (str[j]-'0') <=26)
		return 1;
 
	return 0;
}
 
int main()
{
	int i;
 
	//freopen("input.txt","r",stdin);
 
	while(init())
	{
		DP[0]=1;
		
		if(valid(1, 1))
			DP[1]+=DP[0];
		if(valid(0, 1))
			DP[1]++;
 
		for(i=2; i<strlen(str); i++)
		{
			if(valid(i, i))
				DP[i]+=DP[i-1];
			if(valid(i-1, i))
				DP[i]+=DP[i-2];
		}
 
		printf("%lld\n", DP[strlen(str)-1]);
	}
 
 
	return 0;
} 
