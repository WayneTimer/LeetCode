/*
Time: O(n)
Space: O(1)
Runtime: 16ms

Hint: DP on a binary tree.

by Timer [linyicx@126.com]
2015.09.25
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define INF 1e7

int max = -INF;
struct TreeNode* origin_root=NULL;

int maxPathSum(struct TreeNode* root)
{
    if (!root) return 0;
    if (!origin_root) origin_root=root;
    int l,r,ret;
    l = maxPathSum(root->left);
    r = maxPathSum(root->right);
    if (l+r+root->val > max) max=l+r+root->val;
    if (origin_root==root)
    {
        ret=max;
        origin_root=NULL;
        max=-INF;
        return ret;
    }
    if (l>r)
        ret=l;
    else
        ret=r;
    ret+=root->val;
    if (ret<0) ret=0;
    return ret;
}
