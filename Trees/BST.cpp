#include "bits/stdc++.h"
using namespace std;
struct Node
{
	int value;
	Node* left;
	Node* right;
};
Node* GetNode(int data)
{
	Node* temp = new Node();
	temp->value = data;
	temp->right = temp->left = NULL;
	return temp;
}
Node* BSTinsert(Node* root, int data)
{
	if(root == NULL) return root = GetNode(data);
	if(data <= root->value) root->left = BSTinsert(root->left, data);
	else if(data > root->value) root->right = BSTinsert(root->right, data);
	return root;
}
void BFStraversaliterative(Node* root)
{
	queue<Node*> q;
	if(root == NULL) return;
	q.push(root);
	while(!q.empty())
	{
		Node* temp = q.front();
		cout << temp->value << " ";
		if(temp->left != NULL) q.push(temp->left);
		if(temp->right != NULL) q.push(temp->right);
		q.pop();
	}
}
void DFStraversal(Node* root)
{
	// inorder traversal
	if(root == NULL) return;
	cout << root->value << " ";
	DFStraversal(root->left);
	DFStraversal(root->right);
}
int BSTheight(Node* root)
{
	if(root == NULL) return -1;
	return 1 + max(BSTheight(root->right), BSTheight(root->left));
}
bool checkBST(Node* root, Node* L, Node* R)
{
	if(root == NULL) return true;
	if(L != NULL && root->value <= L->value) return false;
	if(R != NULL && root->value > R->value) return false;
	if(checkBST(root->left, L, root) && checkBST(root->right, root, R)) return true;
	else return false;
}
Node* FindMax(Node* root)
{
	if(root == NULL) return root;
	while(root->right != NULL) root = root->right;
	return root;
}
Node* FindMin(Node* root)
{
	if(root == NULL) return root;
	while(root->left != NULL) root = root->left;
	return root;
}
Node *BSTsearch(Node* root, int val)
{
	if(root == NULL) return root;
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* temp = q.front();
		if(temp -> value == val) return temp;
		if(temp -> right != NULL) q.push(temp->right);
		if(temp -> left != NULL) q.push(temp->left);
		q.pop();
	}
}
Node* Delete(Node* root, int val)
{
	if(root == NULL) return root;
	if(val < root->value) root->left = Delete(root->left, val);
	else if(val > root->value) root->right = Delete(root->right, val);
	else
	{
		if(root->right == NULL && root->left == NULL)
		{
			delete root;
			root = NULL;
		}
		else if(root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
			temp = NULL;
		}
		else if(root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
			temp = NULL;
		}
		else
		{
			Node* temp = FindMin(root->right);
			root->value = temp->value;
			root->right = Delete(root->right, temp->value);
		}
	}
	return root;
}
int inorderSuccessor(Node* root, int val)
{
	 Node* temp = BSTsearch(root, val);
	 if(temp->right != NULL) return FindMin(temp->right)->value;
	 else
	 {
	 	Node* ancestor = NULL;
	 	Node* curr = root;
	 	while(curr->value != val)
	 	{
	 		if(val < curr->value)
	 		{
	 			ancestor = curr;
	 			curr = curr->left;
	 		}
	 		else
	 		{
	 			curr = curr->right;
	 		}
	 	}
	 	return ancestor->value;
	 }
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		Node* root = NULL;
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			root = BSTinsert(root, x);
		}
		BFStraversaliterative(root);
		cout << endl;
		DFStraversal(root);
		cout << endl;
		cout << "Height of tree is " << BSTheight(root) << endl;
		cout << checkBST(root, NULL, NULL) << endl;
		cout << "Minimum is " <<FindMin(root)->value << endl << "Maximum is " << FindMax(root)->value << endl;
		int del; cin >> del;
		cout << BSTsearch(root, del)->value << endl;
		root = Delete(root, del);
		DFStraversal(root);
		cout << endl;
		int success;  cin >> success;
		cout << "inorder successor of " << success << " is " << inorderSuccessor(root, success);
		if(t != 0) cout << endl;
	}
 	return 0;
}
