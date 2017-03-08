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

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	int T;
	long long N;

	cin >> T;

	while (T--)
	{
		cin >> N;
		if (N % 3)
			cout << "Hemlata\n";
		else
			cout << "Ragini\n";
	}

	return 0;
}
