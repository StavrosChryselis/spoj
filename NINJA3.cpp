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

#include <iostream>
 
using namespace std;
 
inline unsigned long long gcd(unsigned long long u, unsigned long long v)
{
	unsigned long long shift;
 
	if (u == 0) return v;
	if (v == 0) return u;
 
	for (shift = 0; ((u | v) & 1) == 0; ++shift)
	{
		u >>= 1;
		v >>= 1;
	}
 
	while ((u & 1) == 0)
		u >>= 1;
 
	do 
	{
 
		while ((v & 1) == 0) 
			v >>= 1;
 
		if (u > v)
		{
			unsigned long long t = v;
			v = u;
			u = t;
		}
 
		v = v - u;                       
	} while (v != 0);
 
 
	return u << shift;
}
 
unsigned long long N, a, b;
 
inline void init()
{
	cin >> N >> a >> b;
	//scanf("%llu %llu %llu", &N, &a, &b);
}
 
inline void solve()
{
	int i;
	unsigned long long GCD;
 
	GCD = gcd(a, b);
 
	for (i = 0; i < GCD; i++)
		//	printf("%llu", N);
		cout << N;
 
//	printf("\n");
	cout << endl;
}
 
int main()
{
	int T;
 
	//scanf("%d", &T);
	cin >> T;
	while (T--)
	{
		init();
		solve();
	}
 
	return 0;
} 
