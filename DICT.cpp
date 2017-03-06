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
#include <ctype.h>
 
#define gc() getchar_unlocked()
using namespace std;
 
inline void printstring(string &A)
{
	int i;
 
	for (i = 0; i < A.length(); i++)
		putchar(A[i]);
}
 
inline void getstring(string &A)
{
	char c;
 
	A.clear();
 
	c = gc();
 
	while (isspace(c))
		c = gc();
 
	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}
 
class trie
{
		struct node
		{
			bool word;
			struct node **childs;
 
			node()
			{
				int i;
 
				word = 0;
				childs = new struct node*[26];
 
				for (i = 0; i < 26; i++)
					childs[i] = nullptr;
			}
 
			~node()
			{
				delete[] childs;
			}
 
			void add(string &A, int pos)
			{
				if (pos == A.length())
				{
					word = 1;
					return;
				}
 
				if (childs[A[pos] - 'a'] == nullptr)
					childs[A[pos] - 'a'] = new struct node();
 
				childs[A[pos] - 'a']->add(A, pos + 1);
			}
 
			struct node *getnode(string &prefix, int pos)
			{
				if (pos == prefix.length())
					return this;
 
				if (childs[prefix[pos] - 'a'] == nullptr)
					return nullptr;
 
				return childs[prefix[pos] - 'a']->getnode(prefix, pos + 1);
			}
 
			void print(string &prefix)
			{
				int i;
 
				if (word)
				{
					printstring(prefix);
					putchar('\n');
				}
 
				for (i = 0; i < 26; i++)
					if (childs[i] != nullptr)
					{
						prefix.push_back(i + 'a');
						childs[i]->print(prefix);
						prefix.pop_back();
					}
			}
 
		};
 
		struct node *root;
 
	public:
		trie()
		{
			root = new struct node;
		}
 
		void addword(string &A)
		{
			root->add(A, 0);
		}
 
		bool retrieve(string &prefix)
		{
			struct node *p = root->getnode(prefix, 0);
			bool flag = 0;
 
			if (p == nullptr)
				return 0;
 
			int i;
 
			for (i = 0; i < 26; i++)
				if (p->childs[i] != nullptr)
				{
					prefix.push_back(i + 'a');
					p->childs[i]->print(prefix);
					prefix.pop_back();
					flag = 1;
				}
 
			return flag;
		}
};
 
trie *T;
 
inline void init()
{
	int i, N;
	string A;
 
	T = new trie();
 
	scanf("%d", &N);
 
	while (N--)
	{
		getstring(A);
		T->addword(A);
	}
}
 
int main()
{
	int N, i;
	string A;
 
//	freopen("input.txt", "r", stdin);
 
	init();
 
	scanf("%d", &N);
 
	for (i = 1; i <= N; i++)
	{
		printf("Case #%d:\n", i);
		getstring(A);
 
		if (!T->retrieve(A))
			printf("No match.\n");
	}
 
	return 0;
} 
