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
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <ctype.h>
#define gc() getchar_unlocked()
#define LIM 30007
 
using namespace std;
 
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
 
typedef struct
{
	int primary;
	bool type;
	int secondary;
}my_pair;
 
bool comp(const my_pair &a, const my_pair &b)
{
	if(a.primary == b.primary)
		return a.type;
	return a.primary < b.primary;
}
 
int N, M;
vector<my_pair> A, Q;
int BIT[LIM];
unordered_map< int, unordered_map<int, int> > memo;
int prevv[1000007];
 
inline void point_update(int pos, int val)
{
	for(; pos <= N;  pos += pos & (-pos))
		BIT[pos] += val;
}
 
inline int point_query(int pos)
{
	int sum = 0;
 
	for(; pos > 0; pos -= pos & (-pos))
		sum += BIT[pos];
 
	return sum;
}
 
inline int range_query(int left, int right)
{
	return point_query(right) - point_query(left - 1);
}
 
inline void init()
{
	my_pair temp;
	int i;
 
	N = FAST_IO();
 
	//scanf("%d", &N);
 
	temp.type = 1;
	for(i=1; i <= N; i++)
	{
		//scanf("%d", &temp.secondary);
		temp.secondary = FAST_IO();
		temp.primary = i;
		A.push_back(temp);
	}
 
	M = FAST_IO();
	//scanf("%d", &M);
 
	temp.type = 0;
	for(i=0; i < M; i++)
	{
		temp.secondary = FAST_IO();
		temp.primary = FAST_IO();
		//scanf("%d %d", &temp.secondary, &temp.primary);
		A.push_back(temp);
		Q.push_back(temp);
	}
 
	sort(A.begin(), A.end(), comp);
 
	for(i=0; i < A.size(); i++)
	{
		if(A[i].type)
		{
			if(prevv[A[i].secondary] != 0)
				point_update(prevv[A[i].secondary], -1);				
 
			point_update(A[i].primary, 1);
			prevv[A[i].secondary] = A[i].primary;
		}
 
		else
			memo[A[i].secondary][A[i].primary] = range_query(A[i].secondary, A[i].primary);
	}
}
 
int main()
{
	int i;
 
	//freopen("input.txt","r",stdin);
	
	init();
 
	for(i=0; i < Q.size(); i++)
		printf("%d\n", memo[Q[i].secondary][Q[i].primary]);
 
	return 0;
} 
