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
#include <string>
#include <string.h>
#include <deque>
#include <unordered_map>
#include <iostream>
 
using namespace std;
 
string codex[]={"01", "1000", "1010", "100", "0", "0010", "110", "0000", "00", "0111", "101", "0100", "11", "10", "111", "0110", "1101", "010", "000", "1", "001", "0001", "011", "1001", "1011", "1100"};
 
int memo[10010];
string code;
 
int N;
 
struct ver
{
	int words;
	struct ver **edges;
};
 
ver *root=NULL;
 
void initialize(ver **vertex)
{
	(*vertex)=new struct ver;
	(*vertex)->words=0;
	(*vertex)->edges=new struct ver *[2];
	(*vertex)->edges[0]=(*vertex)->edges[1]=NULL;
}
 
void addword(ver **vertex, string word, int pos)
{
	if(*vertex==NULL)
		initialize(vertex);
 
	if(pos==word.size())
	{
		(*vertex)->words++;
		return;
	}
 
	char k=word[pos];
 
	addword(&(*vertex)->edges[k-'0'], word, pos+1);
}
 
void free_trie(ver **vertex)
{
	if((*vertex)==NULL)
		return;
 
	free_trie(&(*vertex)->edges[0]);
	free_trie(&(*vertex)->edges[1]);
	delete *vertex;
}
 
void query(ver *vertex, int start, int pos)
{
	if(vertex==NULL || pos>code.length())
		return;
 
	char k=code[pos];
	if(vertex->words!=0)
		memo[pos]+=memo[start]*vertex->words;
 
	query(vertex->edges[k-'0'], start, pos+1);
}
 
void iinit()
{
	char c;
	string ctemp;
	string temp;
	int i, j;
 
	free_trie(&root);
	root=NULL;
	memset(memo, 0, sizeof(memo));
	code.clear();
 
	memo[0]=1;
 
	cin>>code;
 
	for(i=0; i<code.length(); i++)
	{
		if(code[i]=='.')
			code[i]='0';
		else
			code[i]='1';
	}
 
	scanf("%d", &N);
 
	for(i=0; i<N; i++)
	{
		cin>>temp;
		ctemp.clear();
 
		for(j=0; j<temp.length(); j++)
			ctemp+=codex[temp[j]-'A'];
		
		addword(&root, ctemp, 0);
	}
}
 
 
int main()
{
	int T;
	int i;
 
	//freopen("input.txt","r",stdin);
 
	scanf("%d", &T);
	
	while(T--)
	{
		iinit();
		for(i=0; i<code.length(); i++)
			if(memo[i]!=0)
				query(root, i, i);
 
		printf("%d\n", memo[code.length()]);
	}
 
	return 0;
} 
