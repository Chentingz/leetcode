/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (41.17%)
 * Likes:    1531
 * Dislikes: 201
 * Total Accepted:    452K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 二分查找
        int low=0, high = nums.size()-1;
        int middle = 0;
        while(low <= high){
            middle = (low+high)/2;
            if(nums[middle] == target)
                break;
            else if(nums[middle] < target)
                low = middle+1;
            else
                high = middle - 1;
        }
        if(low <= high) // 在序列里找到给定值
            return middle;
        int insertIndex = target > nums[middle] ? middle+1 : middle;
        insertIndex = insertIndex < 0 ? 0 : insertIndex;
      //  insertIndex = insertIndex > nums.size()-1 ? nums.size()-1 : insertIndex;
        return insertIndex;
    }
};

