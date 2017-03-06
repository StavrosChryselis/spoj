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
#include <algorithm>
#include <climits>
 
#define ll long long
using namespace std;
 
ll ans;
int N;
 
inline ll solve()
{
	ll curr = 0, num;
 
	cin >> N;
	ans = LLONG_MAX;
 
	while (N--)
	{
		cin >> num;
		curr += num;
		ans = min(ans, curr);
	}
 
	if (ans <= 0)
		return 1LL - ans;
	else
		return 0;
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
 
	int T;
 
	cin >> T;
 
	while (T--)
		cout << solve() << "\n";
 
	return 0;
} 
