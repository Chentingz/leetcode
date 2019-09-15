/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (41.86%)
 * Likes:    1721
 * Dislikes: 3699
 * Total Accepted:    682.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int swapLastElementIndex = nums.size()-1;  //
        for(int i=0; i<=swapLastElementIndex; ++i)
        {
            for(int j=i+1; j<=swapLastElementIndex; ++j) // 在除nums[i]的后续序列里查找重复项
                if(nums[j] == nums[i]){
                    swap(nums[j], nums[swapLastElementIndex--]);
                    if(swapLastElementIndex != i && nums[swapLastElementIndex] == nums[i])
                        swapLastElementIndex--;
                }
                    
                    
        } 
        int length = swapLastElementIndex + 1;
        sort(nums, length);
        return length;
    }
    void swap(int& x, int& y){
        if(x != y){
            int tmp = x;
            x = y;
            y = tmp;
        }
    }
    // 冒泡排序
    void sort(vector<int>& nums, int size){
        for(int i=1; i<size; ++i){
            for(int j=0; j<size-i; ++j){
                if(nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }
    }
};

