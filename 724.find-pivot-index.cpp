/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 *
 * https://leetcode.com/problems/find-pivot-index/description/
 *
 * algorithms
 * Easy (42.10%)
 * Likes:    747
 * Dislikes: 175
 * Total Accepted:    90.3K
 * Total Submissions: 214.2K
 * Testcase Example:  '[1,7,3,6,5,6]'
 *
 * Given an array of integers nums, write a method that returns the "pivot"
 * index of this array.
 * 
 * We define the pivot index as the index where the sum of the numbers to the
 * left of the index is equal to the sum of the numbers to the right of the
 * index.
 * 
 * If no such index exists, we should return -1. If there are multiple pivot
 * indexes, you should return the left-most pivot index.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * nums = [1, 7, 3, 6, 5, 6]
 * Output: 3
 * Explanation: 
 * The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the
 * sum of numbers to the right of index 3.
 * Also, 3 is the first index where this occurs.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * nums = [1, 2, 3]
 * Output: -1
 * Explanation: 
 * There is no index that satisfies the conditions in the problem
 * statement.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of nums will be in the range [0, 10000].
 * Each element nums[i] will be an integer in the range [-1000, 1000].
 * 
 * 
 * 
 * 
 */
/*
*   思路：naive算法
*   1.pivot=0
*   2.若pivot左子序列 != pivot右子序列，pivot++，直到pivot=nums.size()
*
*/
// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int numsLen = nums.size();
        if(numsLen == 0) return -1;   // 序列为空
        int pivot = 0;
        while(pivot != numsLen && sum(nums,0, pivot-1) != sum(nums, pivot+1, numsLen-1))
            pivot++;
        return pivot != numsLen ? pivot : -1;


    }
    int sum(vector<int>& nums, int startIndex, int endIndex){
        int sum = 0;
        for(int i=startIndex; i<=endIndex; ++i)
            sum += nums[i];
        return sum;
    }
};
// @lc code=end

