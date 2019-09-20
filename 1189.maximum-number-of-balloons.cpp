/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 *
 * https://leetcode.com/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (63.66%)
 * Likes:    43
 * Dislikes: 11
 * Total Accepted:    7.7K
 * Total Submissions: 12.2K
 * Testcase Example:  '"nlaebolko"'
 *
 * Given a string text, you want to use the characters of text to form as many
 * instances of the word "balloon" as possible.
 * 
 * You can use each character in text at most once. Return the maximum number
 * of instances that can be formed.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: text = "nlaebolko"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: text = "loonbalxballpoon"
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: text = "leetcode"
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= text.length <= 10^4
 * text consists of lower case English letters only.
 * 
 */

 /*
 *  思路：
 *  1.先统计text中balon各个字符的个数，用哈希表存储下来
 *  2.尝试取各个字符，如果能够组成一个balloon，那么哈希表中相应字符的个数-1或-2，同时ballon计数器+1
 *  3.重复2，直到不能组成一个balloon,跳4
 *  4.返回ballon计数器
 *
 */
class Solution {
public:
   int maxNumberOfBalloons(string text) {
        if(text.size()<1 || text.size()>1e4)    return 0;
        map<char,int> charCounterMap = {{'b',0}, {'a',0}, {'l',0}, {'o',0}, {'n',0}};
        for(int i=0;i<text.size();++i){
            if(text[i] == 'b' || text[i] == 'a' || text[i] == 'l' || text[i] == 'o' || text[i] == 'n')
                charCounterMap[text[i]] = charCounterMap[text[i]] + 1;
        }
        int countBalloon = 0;
        while(charCounterMap['b']>=1 && charCounterMap['a']>=1 && charCounterMap['l']>=2 && charCounterMap['o']>=2 && charCounterMap['n']>=1){
            charCounterMap['b'] = charCounterMap['b']-1;
            charCounterMap['a'] = charCounterMap['a']-1;
            charCounterMap['l'] = charCounterMap['l']-2;
            charCounterMap['o'] = charCounterMap['o']-2;
            charCounterMap['n'] = charCounterMap['n']-1;
            countBalloon++;
        }
        return countBalloon;
    }
};

