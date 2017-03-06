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
#include <string>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
int main()
{
	string A, B;
	string sum;
	int T;
	
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	while(T--)
	{
		cin>>A>>B;
 
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
 
		sum=to_string(stoi(A, nullptr, 10) + stoi(B, nullptr, 10));
		reverse(sum.begin(), sum.end());
 
		printf("%d\n", stoi(sum, nullptr, 10));
	}
 
	return 0;
} 
