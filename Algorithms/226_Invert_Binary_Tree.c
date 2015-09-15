/*
Time: O(n)
Space: O(1)
Runtime: 0ms

by Timer [linyicx@126.com]
2015.09.15
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root)
    {
        root->left = (long)root->left ^ (long)root->right;
        root->right = (long)root->right ^ (long)root->left;
        root->left = (long)root->left ^ (long)root->right;
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}
