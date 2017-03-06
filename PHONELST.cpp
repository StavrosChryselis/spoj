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
#include <vector>
 
using namespace std;
 
bool init()
{
	int N;
	int i;
 
	char temp[11];
	vector<string> ALL;
	string str;
 
	scanf("%d", &N);
 
	for(i=0; i<N; i++)
	{
		scanf("%s", temp);
		str=temp;
		ALL.push_back(str);
	}
 
	sort(ALL.begin(), ALL.end());
 
	for(i=0; i<ALL.size()-1; i++)
		if(ALL[i+1].substr(0, ALL[i].length())==ALL[i])
			return 0;
	return 1;
}
 
int main()
{
	int K;
	int i;
 
	scanf("%d", &K);
 
	for(i=0; i<K; i++)
	{
		if(init()==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
 
	return 0;
} 
