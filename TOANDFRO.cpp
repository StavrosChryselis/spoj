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
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;
 
string S;
int col;
int rows;
 
inline bool init()
{
	scanf("%d", &col);
 
	if(col == 0)
		return 0;
 
	cin>>S;
 
	rows = S.size() / col;
 
	return 1;
}
 
inline string solve()
{
	int i, j;
	vector< string > A(rows);
	string res = "";
 
	for(i=0; i<A.size(); i++)
		A[i].resize(col);
 
	for(i=0; i<S.size(); i++)
		A[i/col][i%col] = S[i];
 
	for(i=1; i<A.size(); i+=2)
		reverse(A[i].begin(), A[i].end());
 
	for(i=0; i<col; i++)
		for(j=0; j<rows; j++)
			res += A[j][i];
	return res;
}
 
int main()
{
	//freopen("input.txt","r",stdin);
 
	while(init())
		printf("%s\n", solve().c_str());
	return 0;
} 
