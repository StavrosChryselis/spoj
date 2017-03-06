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
#include <stack>
 
using namespace std;
 
stack<char> S;
char str[401];
 
int main()
{
	int T, i;
 
	//freopen("input.txt","r",stdin);
	scanf("%d", &T);
 
	while(T--)
	{
		scanf("%s\n", str);
 
		for(i=0; i<strlen(str); i++)
		{
			if(str[i]=='(')
				continue;
			else if(str[i]==')')
			{
				printf("%c", S.top());
				S.pop();
			}
 
			else if(str[i]>='a' && str[i]<='z')
				printf("%c", str[i]);
			else
				S.push(str[i]);
		}
		printf("\n");
	}
 
	return 0;
} 
