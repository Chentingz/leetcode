/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (50.72%)
 * Likes:    1307
 * Dislikes: 43
 * Total Accepted:    418.3K
 * Total Submissions: 824.2K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * Given two binary trees, write a function to check if they are the same or
 * not.
 * 
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
 * 
 * Example 1:
 * 
 * 
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:     1         1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * Output: false
 * 
 * 
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
 
 /*
 *  思路：采用相同的方法对两颗二叉树进行遍历，得到序列1和序列2，比较序列是否相等
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p && q || p && !q) return false;
        if(p->val != q->val) return false;

        vector<int> traverseSeq1, traverseSeq2;
        preorderTraversal(p,traverseSeq1);
        preorderTraversal(q,traverseSeq2);
        return traverseSeq1 == traverseSeq2 ? true : false;
    }
    void preorderTraversal(TreeNode* p,vector<int>& traverseSeq){
        if(p){
            traverseSeq.push_back(p->val);
            preorderTraversal(p->left, traverseSeq);
            preorderTraversal(p->right, traverseSeq);
        }
        else{
            traverseSeq.push_back(INT_MIN);
        }
    }
};

