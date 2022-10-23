#include "bits/stdc++.h"
using namespace std;
struct TriNode
{
	bool isLeaf;
	TriNode* children[26];
};
TriNode* GetNode()
{
	TriNode* temp = new TriNode();
	temp->isLeaf = false;
	for(int i = 0; i < 26; i++) temp->children[i] = NULL;
	return temp;
}
TriNode* Insert(TriNode* root, string key)
{
	TriNode* temp = root;
	for(int i = 0; i < key.length(); i++)
	{
		if(temp->children[key[i]-'a'] == NULL) temp->children[key[i]-'a'] = GetNode();
		temp = temp->children[key[i]-'a'];
	}
	temp->isLeaf = true;
	return root;
}
bool Triesearch(TriNode* root, string key)
{
	if(root == NULL) return false;
	for(int i = 0; i < key.length(); i++)
	{
		if(root->children[key[i]-'a'] == NULL) return false;
		root = root->children[key[i]-'a'];
	}
	return root->isLeaf;
}	
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		TriNode* root = GetNode();
		for(int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			root = Insert(root, s);
		}
		string key;
		cin >> key;
		cout << Triesearch(root, key);
		if(t != 0) cout << endl;
	}
 	return 0;
}
