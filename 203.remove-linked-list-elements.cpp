/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (36.44%)
 * Likes:    962
 * Dislikes: 59
 * Total Accepted:    251K
 * Total Submissions: 688.5K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        
        ListNode* pre=NULL,*cur=head;
        //处理头结点元素与所去除元素相等的情况
        while(cur&&cur->val==val) {
            head=head->next; 
            cur->next =NULL;
            cur=head;
        }
        if(head==NULL) return head;
        //处理一般情况
        cur=head->next; pre=head;
        while(cur){
            if(cur->val==val){
                pre->next=cur->next;
                cur->next=NULL;
                cur=pre->next;
            }
            else{
               pre= pre->next;
               cur=cur->next;
            }      
        }
        return head;
    }
};

