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
#include <queue>
 
using namespace std;
 
priority_queue<int> Godzilla, MechaGodzilla;
int NG, NM;
 
int main()
{
	int T;
	int i;
	int num;
 
	scanf("%d", &T);
 
	while(T--)
	{
		scanf("%d %d", &NG, &NM);
 
		Godzilla = priority_queue <int>();
		MechaGodzilla = priority_queue <int>();
 
		for(i=0; i<NG; i++)
		{
			scanf("%d", &num);
			Godzilla.push(num);
		}
 
		for(i=0; i<NM; i++)
		{
			scanf("%d", &num);
			MechaGodzilla.push(num);
		}
 
		while(!Godzilla.empty() && !MechaGodzilla.empty())
		{
			if(MechaGodzilla.top() <= Godzilla.top())
				MechaGodzilla.pop();
			else
				Godzilla.pop();
		}
 
		if(Godzilla.empty())
			printf("MechaGodzilla\n");
		else
			printf("Godzilla\n");
	}
 
	return 0;
} 
