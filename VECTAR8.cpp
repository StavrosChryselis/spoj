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
#include <string>
#include <algorithm>
 
#define MAXN 1000000
using namespace std;
 
bool not_prime[1000007];
vector< pair<int, int> > primes;
 
bool check(int num)
{
	string temp = to_string(num);
 
	int i;
 
	for (i = 0; i < temp.size(); i++)
		if (temp[i] == '0')
			return 0;
 
	for (i = 0; i < temp.size() - 1; i++)
	{
		temp[i] = '0';
		if (not_prime[stoi(temp)])
			return 0;
	}
 
	return 1;
}
 
inline void sieve()
{
	int i, j;
 
	not_prime[1] = 1;
 
	primes.push_back(make_pair(2, 1));
 
	for (i = 4; i <= MAXN; i += 2)
		not_prime[i] = 1;
 
	for (i = 3; i <= MAXN; i += 2)
		if (!not_prime[i])
		{
			if (check(i))
				primes.push_back(make_pair(i, primes.size() + 1));
 
			for (j = i + i; j <= MAXN; j += i)
				not_prime[j] = 1;
		}
}
 
int main()
{
	int T, num;
	vector<pair<int, int> > ::iterator ii;
 
	sieve();
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d", &num);
		ii = upper_bound(primes.begin(), primes.end(), make_pair(num, 10000000));
		if (ii == primes.end())
		{
			ii = prev(ii);
			printf("%d\n", ii->second);
		}
 
		else
			printf("%d\n", ii->second - 1);
	}
 
	return 0;
} 
