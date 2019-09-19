/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (36.81%)
 * Likes:    1297
 * Dislikes: 3073
 * Total Accepted:    417K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!nums2.size())   return;
        if(!nums1.size() && nums2.size()){
            for(int i=0; i<n; ++i)
                nums1[m+i] = nums2[i];
            return;
        }
        // 插入排序 O(n^2)
        for(int i=0; i<n; ++i)
            nums1[m+i] = nums2[i];
        int i=0; int j=m;
        while(i<=j && j<(m+n)){
            if(i==j){
                j++;
                i=0;
                continue;
            }
                
            if(nums1[i] > nums1[j]){
                swap(nums1[i], nums1[j]);
                i=0;
            }
            else{
                i++;
            }
        }
    }
    void swap(int& x, int& y){
        int tmp = x;
        x = y;
        y = tmp;
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!nums2.size())   return;
        if(!nums1.size() && nums2.size()){
            for(int i=0; i<n; ++i)
                nums1[m+i] = nums2[i];
            return;
        }
        // 归并排序 O(nlogn)
        // TODO
                

};

