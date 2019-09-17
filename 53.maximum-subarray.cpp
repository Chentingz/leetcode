/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.51%)
 * Likes:    5081
 * Dislikes: 191
 * Total Accepted:    627.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = 0;
        for(int i=0; i<nums.size(); ++i){
            sum = 0;
            for(int j=i; j<nums.size(); ++j){
                if( (sum += nums[j]) > max)
                    max = sum;
             }
        }
        return max;
    }
    // int sum(vector<int>& nums, int lowerBound, int upperBound){
    //     int result = 0;
    //     for(int i=lowerBound; i<=upperBound; ++i){
    //         result += nums[i];
    //     }
    //     return result;
    // }

};

