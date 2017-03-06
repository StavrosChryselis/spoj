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
 
using namespace std;
 
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
				temp->data++;
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
 
	int qq(struct node *i, struct node *j, int l, int r, int k)
	{
		if (l == r)
			return l;
 
		int count = j->left->data - i->left->data;
		int mid = (l + r) >> 1;
 
		if (count >= k)
			return qq(i->left, j->left, l, mid, k);
 
		return qq(i->right, j->right, mid + 1, r, k - count);
	}
 
 
public:
	PersistentSegmentTree(int r)
	{
		struct node *temp;
		range = r;
		trees.push_back(temp);
		init(&trees.back(), 1, range);
	}
 
	inline void update(int pos)
	{
		trees.push_back(trees.back()->insert(1, range, pos));
	}
 
	inline int query(int i, int j, int k)
	{
		return qq(trees[i], trees[j], 1, range, k);
	}
 
	~PersistentSegmentTree()
	{
		int i;
 
		for (i = 0; i < trees.size(); i++)
			delete trees[i];
	}
};
 
PersistentSegmentTree *T;
unordered_map<int, int> MAP, RMAP;
int N, M;
 
inline void init()
{
	int i, num, c = 1;
	vector<int> A, B;
 
	scanf("%d %d", &N, &M);
	T = new PersistentSegmentTree(N);
 
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		A.push_back(num);
		B.push_back(num);
	}
 
	sort(A.begin(), A.end());
 
	MAP[A[0]] = 1;
	RMAP[1] = A[0];
	c++;
 
	for (i = 1; i < A.size(); i++)
	{
		if (A[i] != A[i - 1])
		{
			MAP[A[i]] = c;
			RMAP[c] = A[i];
			c++;
		}
	}
 
	for (i = 0; i < B.size(); i++)
		T->update(MAP[B[i]]);
}
 
inline int solve()
{
	int i, j, k;
 
	scanf("%d %d %d", &i, &j, &k);
 
	return RMAP[T->query(i - 1, j, k)];
}
 
int main()
{
	int i;
 
	//freopen("input.txt", "r", stdin);
 
	init();
 
	for (i = 0; i < M; i++)
		printf("%d\n", solve());
 
	return 0;
} 
