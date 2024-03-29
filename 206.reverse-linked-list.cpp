/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (56.86%)
 * Likes:    2851
 * Dislikes: 69
 * Total Accepted:    693.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 * 
 */
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
 *  1.声明指针cur指向当前结点，指针post保存当前结点的下一个结点，newHead指向翻转链表
 *  2.将指针cur指向的结点用头插法插入newHead中，然后指针cur后移
 *  3.cur不指向NULL，则重复2
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)   return head;    // 链表为空或只有1个元素
        ListNode* cur = head, *post = head->next, *newHead = NULL;
        while(cur){
            post = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = post;
        }
        return newHead;
    }
};

