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
#include <limits.h>
#include <ctype.h>
 
#define gc() getchar_unlocked()
 
using namespace std;
 
int N;
 
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
	long long res = 1, res2 = 1;
	int i, j, num;
	int MIN = INT_MAX, MIN_I, MIN_J;
	vector<int> A;
 
	//freopen("input.txt","r",stdin);
 
	N = FAST_IO();
 
	//scanf("%d", &N);
 
	for(i = 0; i < N; i++)
	{
		num = FAST_IO();
 
		//scanf("%d", &num);
 
		if(num % N == 0)
		{
			printf("%d %d\n", i, i);
			return 0;
		}
 
		A.push_back(num);
		res *= num;
		res %= N;
 
		if(res == 0)
		{
			res2 = 1;
 
			for(j = i;  (res2 * A[j]) % N != 0; j--)
				res2 = (res2 * A[j]) % N;
 
			if(i - j + 1 < MIN)
			{
				MIN = i - j + 1;
				MIN_I = j;
				MIN_J = i;
			}
 
			res = A.back();
		}
	}
 
	if(MIN == INT_MAX)
		printf("-1\n");
	else
		printf("%d %d\n", MIN_I, MIN_J);
 
	return 0;
} 
