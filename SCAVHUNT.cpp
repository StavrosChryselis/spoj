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
#include <iostream>
#include <string>
using namespace std;
 
unordered_map<string, string> mapn, mapr;
string start, finish;
string A, B;
 
void init()
{
	int N, i;
 
	mapn.clear();
	mapr.clear();
	scanf("%d", &N);
 
	cin>>start>>finish;
	mapn[start]=finish;
 
	for(i=0; i<N-2; i++)
	{
		cin>>A>>B;
		mapn[A]=B;
		mapr[B]=A;
	}
 
	for(1; mapr.find(start)!=mapr.end(); start=mapr[start]);
	for(1; mapn.find(finish)!=mapn.end(); finish=mapn[finish]);
}
 
int main()
{
	int T, i;
	string curr;
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
 
	for(i=1; i<=T; i++)
	{
		init();
 
		printf("Scenario #%d:\n", i);
 
		for(curr=start; curr!=finish; curr=mapn[curr])
			printf("%s\n", curr.c_str());
		printf("%s\n\n", curr.c_str());
	}
 
	return 0;
} 
