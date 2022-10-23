#include "bits/stdc++.h"
using namespace std;
vector<int> preorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(A == NULL) return ans;
    TreeNode* curr = A;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode* pre = curr->left;
            while(pre->right != NULL && pre->right != curr) pre = pre->right;
            if(pre->right == NULL)
            {
                pre->right = curr;
                ans.push_back(curr->val);
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}
int main()
{
	return 0;
}