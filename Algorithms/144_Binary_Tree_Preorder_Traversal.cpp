/*
Time: O(n)
Space: O(1)
Runtime: 0ms

by Timer [linyicx@126.com]
2015.12.26
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    void traversal(vector<int>& ret, TreeNode* x)
    {
        ret.push_back(x->val);
        if (x->left) traversal(ret,x->left);
        if (x->right) traversal(ret,x->right);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        ret.clear();
        if (root) traversal(ret,root);
        return ret;
    }
};
