/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (77.71%)
 * Likes:    342
 * Dislikes: 1192
 * Total Accepted:    154.8K
 * Total Submissions: 198.8K
 * Testcase Example:  '"Hello"'
 *
 * Implement function ToLowerCase() that has a string parameter str, and
 * returns the same string in lowercase.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "Hello"
 * Output: "hello"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "here"
 * Output: "here"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "LOVELY"
 * Output: "lovely"
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0; i<str.size(); ++i){
            if(str[i] >='A' && str[i] <= 'Z')
                str[i] = str[i] - 'A' + 'a';
        }
        return str;
    }
};
// @lc code=end

