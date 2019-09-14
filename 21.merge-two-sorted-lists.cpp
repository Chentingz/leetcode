/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (48.80%)
 * Likes:    2621
 * Dislikes: 380
 * Total Accepted:    677.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l1Tmp=l1,*l2Tmp=l2;
        ListNode* l3=NULL,*l3Tmp=l3;
        
        // 确定首节点
        if(l1Tmp->val >= l2Tmp->val){
            *l3 = ListNode(l2Tmp->val);
            l2Tmp = l2Tmp->next;
        }
        else{
            *l3 = ListNode(l1Tmp->val);
            l1Tmp = l1Tmp->next;
        }
        l3Tmp = l3;
        while(l1Tmp && l2Tmp){
            if(l1Tmp->val >= l2Tmp->val){
                *l3Tmp->next = ListNode(l2Tmp->val);
                l3Tmp = l3Tmp->next;
                l2Tmp = l2Tmp->next;
            }
            else if(l1Tmp->val < l2Tmp->val){
                *l3Tmp->next = ListNode(l1Tmp->val);
                l3Tmp = l3Tmp->next;
                l1Tmp = l1Tmp->next;
            }
        }
        if(l1Tmp == NULL)
            // l3Tmp->next = l2Tmp;
            while(l2Tmp){
                *l3Tmp->next = ListNode(l2Tmp->val);
                l3Tmp = l3Tmp->next;
                l2Tmp = l2Tmp->next;
            }
        if(l2Tmp == NULL)
            // l3Tmp->next = l1Tmp;
            while(l1Tmp){
                *l3Tmp->next = ListNode(l1Tmp->val);
                l3Tmp = l3Tmp->next;
                l1Tmp = l1Tmp->next;
            }
        return l3;
    }
};

