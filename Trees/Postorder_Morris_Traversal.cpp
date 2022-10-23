#include "bits/stdc++.h"
using namespace std;
vector<int> postorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<int> s;
    if(A == NULL) return ans;
    TreeNode* curr = A;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            s.push(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode* pre = curr->left;
            while(pre->right != NULL && pre->right != curr) pre = pre->right;
            if(pre->right == NULL)
            {
                pre->right = curr;
                s.push(curr->val);
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                while(curr->val != s.top())
                {
                    ans.push_back(s.top());
                    s.pop();
                }
                curr = curr->right;
            }
        }
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main()
{
	return 0;
}