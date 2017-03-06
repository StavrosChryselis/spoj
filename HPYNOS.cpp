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
#include <string>
 
using namespace std;
 
char str[15];
bool V[300];
 
int break_num(int num)
{
	int i;
	int sum=0;
	
	strcpy(str,to_string(num).c_str());
	for(i=0; i<strlen(str); i++)
		sum+=(str[i]-'0')*(str[i]-'0');
 
	return sum;
}
 
int main()
{
	int num, temp;
	int c=0;
 
	scanf("%d", &num);
	
 
	while(num!=1)
	{
		num=break_num(num);
		if(V[num])
		{
			printf("-1\n");
			return 0;
		}
 
		V[num]=1;
		c++;
	}
 
	printf("%d\n", c);
	return 0;
}
 
