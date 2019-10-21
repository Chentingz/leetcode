/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (64.21%)
 * Likes:    908
 * Dislikes: 581
 * Total Accepted:    518K
 * Total Submissions: 805.2K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * You may assume all the characters consist of printable ascii
 * characters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * 
 */
/*
*   思路：两指针 + 交换
*   1.指针i从前往后移动，指针j从后往前移动
*   2.交换s[i]和s[j]
*
*   时间复杂度：O(n)
*   空间复杂度：O(1)
*/
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        // based on swap
        int sLen = s.size();
        int tmp;
        for(int i=0,j=sLen-1; i<j; ++i, --j){
            if(s[i] != s[j]){
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
};
// @lc code=end

