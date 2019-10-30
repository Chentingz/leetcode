/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (52.79%)
 * Likes:    347
 * Dislikes: 223
 * Total Accepted:    94.9K
 * Total Submissions: 179.7K
 * Testcase Example:  '"USA"'
 *
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * 
 * Note: The input will be a non-empty word consisting of uppercase and
 * lowercase latin letters.
 * 
 */

/*
*   算法：
*   1.检查第一个字符是否大写，若是大写跳2，否则跳3
*   2.遍历剩余字符，若剩余字符全是大写或全是小写，返回true，否则返回false
*   3.遍历剩余字符，若有字符大写返回false，否则返回true
*/
// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstLetterIsCapital = word[0] >= 'A' && word[0] <= 'Z' ? true : false;
        bool secondLetterIsCapital = word[1] >= 'A' && word[1] <= 'Z' ? true : false;

        if(firstLetterIsCapital){
            for(int i=2; i<word.size(); ++i)
                if(secondLetterIsCapital && word[i] >= 'a' && word[i] <= 'z' || !secondLetterIsCapital && word[i] >= 'A' && word[i] <= 'Z')
                    return false;
            return true;
        }
        else{
            for(int i=1; i<word.size(); ++i)
                if(word[i] >= 'A' && word[i] <= 'Z')
                    return false;
            return true;
        }

    }

};
// @lc code=end

