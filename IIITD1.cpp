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
#include <cmath>

#define ll long long
using namespace std;

int main()
{
	int T;
	ll n1, n2;

//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	cin >> T;

	while (T--)
	{
		cin >> n1;
		n2 = abs(n1);
		n2 += pow(10, int(log10(n2)));
		if (!n1)
			cout << "1\n";
		else
			cout << n2 - n1 << "\n";
	}

	return 0;
}
