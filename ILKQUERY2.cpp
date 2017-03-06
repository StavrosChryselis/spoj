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

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ctype.h>
#define gc() getchar()
 
using namespace std;
 
int A[100007];
int N, Q;
unordered_map<int, int> MAP;
 
inline int FAST_IO()
{
	char ch;
	int val = 0;
	bool neg = 0;
 
	ch = gc();
	while (isspace(ch) && ch != EOF)
		ch = gc();
 
	if (ch == '-')
	{
		neg = 1;
		ch = gc();
	}
 
	val = 0;
	while (isdigit(ch))
	{
		val = (val * 10) + (ch - '0');
		ch = gc();
	}
	if (!neg)
		return val;
	return -val;
}
 
class PersistentSegmentTree
{
	struct node
	{
		long long data;
		struct node *left;
		struct node *right;
 
		node(int d = 0)
		{
			data = d;
			left = right = nullptr;
		}
 
		struct node *insert(int i, int j, int pos)
		{
			struct node *temp = new struct node();
 
			if (i == j)
			{
				*temp = *this;
 
				if (temp->data)
					temp->data = 0;
				else
					temp->data = 1;
 
				return temp;
			}
 
			int mid = (i + j) >> 1;
 
			if (pos <= mid)
			{
				temp->right = this->right;
				temp->left = this->left->insert(i, mid, pos);
				temp->data = temp->left->data + temp->right->data;
				return temp;
			}
 
			else
			{
				temp->left = this->left;
				temp->right = this->right->insert(mid + 1, j, pos);
				temp->data = temp->left->data + temp->right->data;
				return temp;
			}
		}
 
		int query(int i, int j, int a, int b)
		{
			if (a == i && b == j)
				return this->data;
 
			int mid = (i + j) >> 1;
 
			if (a > mid)
				return this->right->query(mid + 1, j, a, b);
			else if (b <= mid)
				return this->left->query(i, mid, a, b);
			else
				return this->left->query(i, mid, a, mid) + this->right->query(mid + 1, j, mid + 1, b);
		}
 
		~node()
		{
			if (this->left != nullptr)
				delete this->left;
 
			if (this->right != nullptr)
				delete this->right;
 
			delete this;
		}
	};
 
	vector<struct node*> trees;
	int range;
 
	void init(struct node **curr, int i, int j)
	{
		*curr = new struct node();
 
		if (i == j)
			return;
 
		int mid = (i + j) >> 1;
 
		init(&(*curr)->left, i, mid);
		init(&(*curr)->right, mid + 1, j);
	}
 
	void only_update(struct node **curr, int i, int j, int pos)
	{
		if (i == j)
		{
			if ((*curr)->data)
			{
				(*curr)->data = 0;
				return;
			}
 
			(*curr)->data = 1;
			return;
		}
 
		int mid = (i + j) >> 1;
 
		if (pos <= mid)
			only_update(&(*curr)->left, i, mid, pos);
		else
			only_update(&(*curr)->right, mid + 1, j, pos);
 
		(*curr)->data = (*curr)->left->data + (*curr)->right->data;
	}
 
public:
	PersistentSegmentTree(int r)
	{
		struct node *temp;
		range = r;
		trees.push_back(temp);
		init(&trees.back(), 1, range);
	}
 
	inline void init_new(int pos)
	{
		trees.push_back(trees[0]->insert(1, range, pos));
	}
 
	inline void update(int num, int pos)
	{
		trees[num] = trees[num]->insert(1, range, pos);
	}
 
	inline int query(int i, int j, int num)
	{
		return trees[num]->query(1, range, i, j);
	}
 
	~PersistentSegmentTree()
	{
		int i;
 
		for (i = 0; i < trees.size(); i++)
			delete trees[i];
	}
};
 
PersistentSegmentTree *T;
 
inline void init()
{
	int i, c;
	vector< pair<int, int> > B;
 
	N = FAST_IO();
	Q = FAST_IO();
 
	T = new PersistentSegmentTree(N);
	B.push_back(make_pair(0, 0));
 
	for (i = 1; i <= N; i++)
	{
		A[i] = FAST_IO();
		B.push_back(make_pair(A[i], i));
	}
 
	sort(B.begin(), B.end());
 
	c = 2;
 
	MAP[B[1].first] = 1;
 
	T->init_new(B[1].second);
 
	for (i = 2; i <= N; i++)
	{
		if (B[i].first != B[i - 1].first)
		{
			MAP[B[i].first] = c++;
			T->init_new(B[i].second);
		}
		else
			T->update(MAP[B[i].first], B[i].second);
	}
}
 
int main()
{
	int k, type, i, j, num;
 
	//freopen("input.txt", "r", stdin);
 
	init();
 
	for (k = 0; k < Q; k++)
	{
		type = FAST_IO();
 
		switch (type)
		{
		case 0:
			i = FAST_IO();
			j = FAST_IO();
			num = FAST_IO();
 
			if (MAP.find(num) == MAP.end())
				printf("0\n");
			else
				printf("%d\n", T->query(i + 1, j + 1, MAP[num]));
			break;
		case 1:
			num = FAST_IO();
			num++;
			T->update(MAP[A[num]], num);
			break;
		}
	}
 
	return 0;
} 
