#include "bits/stdc++.h"
using namespace std;
struct TriNode
{
	TriNode* children[2];
};
TriNode* GetNode()
{
	TriNode* temp = new TriNode();
	for(int i = 0; i < 2; i++) temp->children[i] = NULL;
	return temp;
}
TriNode* Insert(TriNode* root, int val)
{
	TriNode* ret = root;
	for(int i = 31; i >= 0; i--)
	{
		if(val>>i & 1)
		{
			if(root->children[1] == NULL) root->children[1] = GetNode();
			root = root->children[1];
		}
		else
		{
			if(root->children[0] == NULL) root->children[0] = GetNode();
			root = root->children[0];
		}
	}
	return ret;
}
int GetMax(TriNode* root, int x)
{
	int ans = 0;
	for(int i = 31; i>=0; i--)
	{
		int check = (x >> i) & (1);
		if(root->children[1-check] != NULL)
		{
			ans = ans | (1 << i);
			root = root->children[1-check];
		}
		else
		{
			root = root->children[check];
		}
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		std::vector<int> A(n);
		std::vector<int> B(m);
		for (int i = 0; i < n; ++i) cin >> A[i];
		for (int i = 0; i < m; ++i) cin >> B[i];
		TriNode* root = GetNode();
		for (int i = 0; i < n; ++i) root = Insert(root, A[i]);
		int ans = 0;
		for (int i = 0; i < m; ++i)
		{
			int temp = GetMax(root, B[i]);
			ans = max(ans, temp);
		}
		cout << ans;
		if(t != 0) cout << endl;
	}
 	return 0;
}
