/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.93%)
 * Likes:    6122
 * Dislikes: 1591
 * Total Accepted:    1.1M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
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
*   思路
*   1.分别用指针i和j指向l1和l2，计算i->val + j->Val + carry，若结果>=10,carry=1，结果%10存储在新链表result中，否则carry=0
*   2.若指针i==NULL，j!=NULL，计算l2剩余位与carry的结果，存在result中；若i != NULL && j==NULL，计算l1剩余位与carry的结果存储在result中
*   3.检查carry位，若为1，则将carry添加到result中
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* i = l1, *j=l2;
        ListNode* result = NULL, *tail=NULL;
        int carry = 0, sum = 0;
        bool isFirstInsert = true; 
        while(i && j){
            carry = (sum = i->val + j->val + carry) >=10 ? 1 : 0;
            ListNode* tmpNode = new ListNode(sum%10);
            if(isFirstInsert){
                isFirstInsert = false;
                result = tmpNode;
                tail = result;
            }
            else{
                tail->next = tmpNode;
                tail = tail->next;
            }


            i = i->next;
            j = j->next;
        }
        while(j){
            carry = (sum = j->val + carry) >=10 ? 1 : 0;
            ListNode* tmpNode = new ListNode(sum%10);
            tail->next = tmpNode;
            tail = tail->next;
            j = j->next;
        }
        while(i){
            carry = (sum = i->val + carry) >=10 ? 1 : 0;
            ListNode* tmpNode = new ListNode(sum%10);
            tail->next = tmpNode;
            tail = tail->next;
            i = i->next;
        }
        if(carry){
            ListNode* tmpNode = new ListNode(1);
            tail->next = tmpNode;
            tail = tail->next;
        }
        return result;
    }
};
// @lc code=end

