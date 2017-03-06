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
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ctype.h>
#define gc() getchar_unlocked()
 
using namespace std;
 
unordered_map<int, bool> A;
vector<int> B;
int N, K;
 
inline int FAST_IO()
{
    char ch;
    int val=0;
    ch=gc();
    while(isspace(ch) && ch!=EOF)
            ch=gc();
    val=0;
    while(isdigit(ch))
    {
        val=(val*10)+(ch-'0');
        ch=gc();
    }
    return val;
}
 
int main()
{
	int i, num, c=0;
 
	//freopen("input.txt","r",stdin);
 
	N=FAST_IO();
	K=FAST_IO();
	//scanf("%d %d", &N, &K);
 
	for(i=0; i<N; i++)
	{
		num=FAST_IO();
		//scanf("%d", &num);
		B.push_back(num);
		A[num]=1;
	}
 
	for(i=0; i<N; i++)
	{
		if(A.find(B[i]+K)!=A.end())
			c++;
	}
	printf("%d\n", c);
 
	return 0;
} 
