/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.11%)
 * Likes:    1601
 * Dislikes: 1462
 * Total Accepted:    539.4K
 * Total Submissions: 1.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 1) return string("");
        else if(strs.size() == 1) return strs[0];
        else{
            string strTmp = strs[0];
            for(int i=1; i<strs.size(); ++i) {
                strTmp = longestCommonPrefix(strs[i], strTmp);
            }
            return strTmp;
        }

    }
    string longestCommonPrefix(string str1, string str2){
        if(str1.size() < str2.size()) {
            return longestCommonPrefix(str1, str2.substr(0, str1.size()));
        }
        else if(str1.size() > str2.size()) {
            return longestCommonPrefix(str1.substr(0, str2.size()), str2);
        }
        else { 
            if(str1[0] != str2[0])
                return string("");
            for(int i=1; i<str1.size(); ++i){
                if(str1[i] != str2[i])
                    return str1.substr(0, i);
            }
            return str1;
        }
    }
};

