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
#include <vector>
#include <utility>
 
using namespace std;
 
int main() 
{
	int n;
	cin >> n;
	int a[n];
	vector<int> v1, v2;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				v1.push_back(a[i]*a[j]+a[k]);
				
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++) {
				if(a[i])
					v2.push_back(a[i]*(a[j]+a[k]));
			}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	long long count = 0;
	pair<vector<int>::iterator, vector<int>::iterator> bounds;
	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		bounds = equal_range(v2.begin(), v2.end(), *it);
		count += bounds.second-bounds.first;
	}
	cout << count << endl;
  
  return 0;
}
