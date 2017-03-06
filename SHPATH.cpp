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
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <ctype.h>
#define INF 1000000000
#define gc() getchar_unlocked()
 
using namespace std;
 
unordered_map<string, int> map;
int N;
vector< vector< pair<int, int> > > G;
 
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
 
inline string gs()
{
	char c;
	string temp;
 
	c = gc();
	while(!isalpha(c))
		c=gc();
 
	temp.push_back(c);
	c = gc();
	while(isalpha(c))
	{
		temp.push_back(c);
		c = gc();
	}
 
	return temp;
}
 
inline void init()
{
	int i, j, E, s, w;
	string temp;
	char c;
 
 
	//scanf("%d\n", &N);
	N = FAST_IO();
 
	map.clear();
	G.clear();
 
	G.resize(N+1);
 
	for(i = 1; i <= N; i++)
	{
		/*
		c = gc();
		temp.clear();
		while(c!='\n')
		{
			temp.push_back(c);
			c = gc();
		}
		*/
 
		temp = gs();
		//scanf("%d", &E);
		E = FAST_IO();
 
		for(j = 0; j < E; j++)
		{
			s = FAST_IO();
			w = FAST_IO();
			//scanf("%d %d\n", &s, &w);
			G[i].push_back(make_pair(s, w));
		}
 
		map[temp] = i;
	}
}
 
inline int dijkstra(int root, int target)
{
	set< pair<int, int> > Q;
	vector<int> D(N+1);
	int i;
	int alt;
	pair<int, int> u;
 
	for(i=1; i<=N; i++)
		D[i] = INF;
 
	D[root] = 0;
 
	Q.insert(make_pair(0, root));
	Q.insert(make_pair(INF, N+1));
 
	while(Q.begin()->first != INF)
	{
		u = *Q.begin();
		Q.erase(Q.begin());
 
		if(u.second == target)
			return u.first;
 
		for(i = 0; i<G[u.second].size(); i++)
		{
			alt = u.first + G[u.second][i].second;
			if(alt < D[G[u.second][i].first])
			{
				D[G[u.second][i].first] = alt;
				Q.insert(make_pair(alt, G[u.second][i].first));
			}
		}
	}
}
 
int main()
{
	int T, i, Q;
	string start, target;
	char c;
 
	//freopen("input.txt","r",stdin);
 
	T = FAST_IO();
	//scanf("%d", &T);
 
	while(T--)
	{
		init();
		Q = FAST_IO();
		//scanf("%d\n", &Q);
 
		for(i = 0; i<Q; i++)
		{
			/*
			start.clear();
			target.clear();
			c = gc();
			while(c!=' ')
			{
				start.push_back(c);
				c = gc();
			}
 
			c = gc();
			while(c!='\n')
			{
				target.push_back(c);
				c = gc();
			}
			*/
 
			start = gs();
			target = gs();
 
			printf("%d\n", dijkstra(map[start], map[target]));
		}
	}
	return 0;
} 
