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
#include <math.h>
 
using namespace std;
 
inline double volume(double r, double h)
{
	return (r * r * h) / 3;
}
 
inline double area(double r, double h)
{
	return r * sqrt(r * r + h * h);
}
 
double R, H;
 
inline void init()
{
	scanf("%lf %lf", &R, &H);
}
 
inline double solve()
{
	if (fabs(volume(R, H) - area(R, H)) <= 1e-8)
		return H;
 
	double lo = 0, hi = H;
	double r;
 
	while (fabs(hi - lo) >= 1e-8)
	{
		double h = (hi + lo) / 2.0;
		double r = h * R / H;
 
		if (volume(r, h) <= 2 * area(R, H) - area(r, h))
			lo = h;
		else
			hi = h;
	}
 
	return lo;
}
 
int main()
{
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		init();
		printf("%.6lf\n", solve());
	}
 
	return 0;
} 
