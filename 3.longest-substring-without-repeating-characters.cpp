/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.94%)
 * Likes:    6953
 * Dislikes: 412
 * Total Accepted:    1.2M
 * Total Submissions: 4.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
/*
*   naive算法
*   思路：
*   - 构造子串，从串s的长度开始构造
*   - 将子串存储到集合中，根据集合长度是否与子串长度相等，来判断子串中是否有重复字符，若有重复则构造长度-1的子串，否则返回子串长度
*
*   例子：
*   - s = "abca"
*   - 构造长度为4的子串"abca"
*   - 判断出"abca"有重复字符
*   - 构造长度为3的子串"abc"和"bca"
*   - "abc"和"bca"均无重复字符，返回最长子串长度3
*
*   Bug:Time Limit Exceeded，需要改进
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sLen = s.size();
        if(sLen <= 0)   return 0;
        if(sLen == 1)   return 1;
        if(sLen == 2)   return s[0] == s[1] ? 1 : 2;

        for(int i=0; i < sLen; ++i){    // 控制子串长度
            int substrLen = sLen - i;
            for(int j=0; j+substrLen-1 != sLen; ++j){    // 构造子串, endIndex = j + substrLen - 1
                if(!hasRepeatingCharaters(s.substr(j, substrLen)))
                    return substrLen;
            }
        }
        return 0;   
    }
    bool hasRepeatingCharaters(string s){
        int sLen = s.size();
        if(sLen == 1)   return false;
        if(sLen == 2)   return s[0] == s[1] ? true : false;

        unordered_set<char> mySet;  // 插入比set快
        for(auto ch : s){
            mySet.insert(ch);
        }
        return mySet.size() == sLen ? false : true;
    }
};
// @lc code=end

