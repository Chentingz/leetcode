/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (61.47%)
 * Likes:    2874
 * Dislikes: 107
 * Total Accepted:    531.7K
 * Total Submissions: 864.7K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */
 
 /*
 *  思路：
 *  1.用哈希表存储元素出现的次数
 *  2.遍历哈希表，找到出现一次的元素
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> count;
        //初始化count
        for(auto n : nums)
            count[n]=0;
        //计算nums[i]的个数
        for(auto n : nums)
            count[n]++;
        //哈希查找只出现一次的元素   
        for(map<int,int>::iterator iter =count.begin(); iter!=count.end(); iter++)
            if (iter->second ==1)
                return iter->first;
        return -1;
    }
};

