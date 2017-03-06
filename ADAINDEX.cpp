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
#include <stdlib.h>
#include <string>
#include <ctype.h>
 
#define gc() getchar()
using namespace std;
 
struct ver
{
	int words;
	int prefixes;
	struct ver **edges;
};
 
void initialize(ver **vertex)
{
	int i;
 
	(*vertex) = (struct ver*)malloc(sizeof(struct ver));
	(*vertex)->words = 0;
	(*vertex)->prefixes = 0;
	(*vertex)->edges = (struct ver**)malloc(sizeof(ver) * 26);
 
	for (i = 0; i<26; i++)
		(*vertex)->edges[i] = NULL;
}
 
void addword(ver **vertex, string &word, int pos = 0)
{
	if (pos == word.size())
	{
		(*vertex)->words++;
		(*vertex)->prefixes++;
		return;
	}
 
	char k = word[pos];
 
	(*vertex)->prefixes++;
	if ((*vertex)->edges[k - 'a'] == NULL)
		initialize(&(*vertex)->edges[k - 'a']);
 
	addword(&(*vertex)->edges[k - 'a'], word, pos + 1);
}
 
int countwords(ver *vertex, string &word, int pos = 0)
{
	if (pos == word.size())
		return vertex->words;
 
	char k = word[pos];
 
	if (vertex->edges[k - 'a'] == NULL)
		return 0;
 
	return countwords(vertex->edges[k - 'a'], word, pos + 1);
}
 
int countprefixes(ver *vertex, string &word, int pos = 0)
{
	if (pos == word.size())
		return vertex->prefixes;
 
	char k = word[pos];
 
	if (vertex->edges[k - 'a'] == NULL)
		return 0;
 
	return countprefixes(vertex->edges[k - 'a'], word, pos + 1);
}
 
inline void next_string(string &A)
{
	A.clear();
 
	char c = gc();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}
 
struct ver *trie;
int N, Q;
 
inline void init()
{
	string S;
 
	scanf("%d %d", &N, &Q);
 
	initialize(&trie);
 
	while (N--)
	{
		next_string(S);
		addword(&trie, S);
	}
}
 
inline int query()
{
	string S;
 
	next_string(S);
	return countprefixes(trie, S);
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
 
	init();
 
	while (Q--)
		printf("%d\n", query());
 
	return 0;
} 
