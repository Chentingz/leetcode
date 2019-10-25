/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (38.80%)
 * Likes:    1162
 * Dislikes: 370
 * Total Accepted:    358.4K
 * Total Submissions: 923.1K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
 *  1.先根遍历，sum -= root->val >=0，则跳2；若该结点为叶子节点，且sum == 0，则返回；否则跳3
 *  2.比较左右子节点的值，选择较大者且（sum -= 左右结点->val >=0）的结点进行遍历，跳1
 *  3.sum += val
 *  
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
    }
};
// @lc code=end

