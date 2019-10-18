/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (37.17%)
 * Likes:    2024
 * Dislikes: 288
 * Total Accepted:    309.4K
 * Total Submissions: 831.2K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 *  思路：
 *  1.将链表中的元素用vector类型的num存储
 *  2.两指针思想，遍历vector，比较num[i] == num[numSize-i-1]
 *  3.若都相等则返回true，否则返回false
 *
 *  时间复杂度：O(n)    
 *  空间复杂度：O(n)
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* tmp = head;
        vector<int> num;
        while(tmp){
            num.push_back(tmp->val);
            tmp = tmp->next;
        }
        int numSize = num.size();
        for(int i=0; i<numSize; ++i){
            if(num[i] != num[numSize - i - 1])
                return false;
        }
        return true;
    }
};
// @lc code=end

