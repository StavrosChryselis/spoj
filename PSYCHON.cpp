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
#define SIEVE_N 10000001
 
using namespace std;
 
bool sieve[SIEVE_N+1];
vector<int> primes;
 
inline void calc_primes()
{
	int i, j;
 
	primes.push_back(2);
 
	for(i=4; i<=SIEVE_N; i+=2)
		sieve[i] = 1;
 
	for(i=3; i<=SIEVE_N; i+=2)
		if(!sieve[i])
		{
			primes.push_back(i);
			for(j=i+i; j<=SIEVE_N; j+=i)
				sieve[j] = 1;
		}
}
 
inline bool psycho(int num)
{
	vector<int> prime_divisors;
	int prime_pos = 0, even = 0, odd = 0, counter = 0, i, prev;
 
	while(sieve[num])
	{
		if(num % primes[prime_pos] == 0)
		{
			prime_divisors.push_back(primes[prime_pos]);
			num /= primes[prime_pos];
		}
		else
			prime_pos++;
	}
 
	prime_divisors.push_back(num);
 
	prev = prime_divisors[0];
	counter++;
 
	for(i=1; i<prime_divisors.size(); i++)
	{
		if(prime_divisors[i] == prev)
			counter++;
		else
		{
			if(counter%2)
				odd++;
			else
				even++;
			counter = 1;
			prev = prime_divisors[i];
		}
	}
 
	if(counter%2)
		odd++;
	else
		even++;
	
	if(even>odd)
		return 1;
	return 0;
}
 
int main()
{
	int T, num;
 
	calc_primes();
 
	scanf("%d", &T);
 
	while(T--)
	{
		scanf("%d", &num);
 
		if(psycho(num))
			printf("Psycho Number\n");
		else
			printf("Ordinary Number\n");
	}
 
	return 0;
} 
