/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 *
 * https://leetcode.com/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (69.42%)
 * Likes:    406
 * Dislikes: 99
 * Total Accepted:    84.4K
 * Total Submissions: 121.5K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * Given the root node of a binary search tree (BST) and a value. You need to
 * find the node in the BST that the node's value equals the given value.
 * Return the subtree rooted with that node. If such node doesn't exist, you
 * should return NULL.
 * 
 * For example, 
 * 
 * 
 * Given the tree:
 * ⁠       4
 * ⁠      / \
 * ⁠     2   7
 * ⁠    / \
 * ⁠   1   3
 * 
 * And the value to search: 2
 * 
 * 
 * You should return this subtree:
 * 
 * 
 * ⁠     2     
 * ⁠    / \   
 * ⁠   1   3
 * 
 * 
 * In the example above, if we want to search the value 5, since there is no
 * node with value 5, we should return NULL.
 * 
 * Note that an empty tree is represented by NULL, therefore you would see the
 * expected output (serialized tree format) as [], not null.
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 *  思路：
 *  从BST（二叉排序树）的定义入手
 *  1.从根节点开始遍历
 *  2.若val == root->val || root == NULL，返回root
 *  3.若val < root->val，则搜索左子树
 *  4.若val > root->val，则搜索右子树
 *  5.
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return (!root || root->val == val) ? root : root->val < val ? searchBST(root->right, val) : searchBST(root->left, val);
    }
};
// @lc code=end

