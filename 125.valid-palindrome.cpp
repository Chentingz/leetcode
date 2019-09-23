/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (32.35%)
 * Likes:    692
 * Dislikes: 2054
 * Total Accepted:    410.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */

 /*
 *  思路：
 *  1.对字符串进行预处理，只保留字母数字，大写字母转成小写，保存在str中
 *  2.判断str是否是回文
 *  
 *  时间复杂度：O(n)
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0) return true;
        string str;
        int i=0,j=0;
        //数据预处理，大写字母转成小写字母，只保留字母，数字
        for(auto c : s){
            if(c>='A'&& c<='Z')
                str.insert(str.end(), c-'A'+'a');
            else if(c>='a'&& c<='z' || c>='0'&& c<='9')
                str.insert(str.end(),c);
            else
                continue;
        }
        //判断str是否是回文
        j=str.size()-1;
        while(i<j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

