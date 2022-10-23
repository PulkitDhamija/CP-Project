#include "bits/stdc++.h"
using namespace std;
struct TriNode
{
	TriNode* children[26];
	int cf;
	int ew;
};
TriNode* GetNode()
{
	TriNode* temp = new TriNode();
	temp->cf = temp->ew = 0;
	for(int i = 0; i < 26; i++) temp->children[i] = NULL;
	return temp;
}
TriNode* Insert(TriNode* root, string key)
{
	TriNode* ret = root;
	for(int i = 0; i < key.length(); i++)
	{
		if(root->children[key[i]-'a'] == NULL) root->children[key[i]-'a'] = GetNode();
		root = root->children[key[i]-'a'];
		root->cf++;
	}
	root->ew++;
	return ret;
}
int CountWordsEqualTo(TriNode* root, string key)
{
	for(int i = 0; i < key.length(); i++)
	{
		if(root->children[key[i]-'a'] == NULL) return 0;
		if(root->children[key[i]-'a'] != NULL && root->children[key[i]-'a']->cf == 0) return 0;
		root = root->children[key[i]-'a'];
	}
	return root->ew;
}
int CountWordsStartWith(TriNode* root, string key)
{
	for (int i = 0; i < key.length(); ++i)
	{
		if(root->children[key[i]-'a'] == NULL) return 0;
		if(root->children[key[i]-'a'] != NULL && root->children[key[i]-'a']->cf == 0) return 0;
		root = root->children[key[i]-'a'];
	}
	return	root->cf;
}
TriNode* Erase(TriNode* root, string key)
{
	TriNode* temp = root;
	for(int i = 0; i < key.length(); i++)
	{
		temp->children[key[i]-'a']->cf--;
		temp = temp->children[key[i]-'a'];
	}
	temp->ew--;
	return root;
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
		string s;
		cin >> s;
		cout << CountWordsEqualTo(root, s) << endl;
		cin >> s;
		cout << CountWordsStartWith(root, s) << endl;
		cin >> s;
		root = Erase(root, s);
		cout << CountWordsEqualTo(root, s) << endl;
		if(t != 0) cout << endl;
	}
 	return 0;
}