/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (53.56%)
 * Likes:    487
 * Dislikes: 576
 * Total Accepted:    400K
 * Total Submissions: 746.8K
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an array of integers, find if the array contains any duplicates.
 * 
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 */

/*
*   思路：
*   1.用hashTable<int, bool>标记num是否存在
*   2.遍历nums，若hashTable[nums[i]]==true，返回true；否则，hashTable[nums[i]] = true
*   3.返回true
*/
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> hashTable;
        for(auto n : nums){
            if(hashTable[n])        // n已经出现过
                return true;
            hashTable[n] = true;
        }
        return false;
    }
};
// @lc code=end

