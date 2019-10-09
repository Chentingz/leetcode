/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (38.30%)
 * Likes:    913
 * Dislikes: 259
 * Total Accepted:    233.2K
 * Total Submissions: 608.1K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */

/*
*   思路：
*   1.同时遍历s和t，若map[s[i]]不存在，则将s[i]和t[i]的映射存储在map中
*   2.检查map中是否有重复映射（如<a,a>, <b,a>，元素a和b同时映射到一个元素），若有则返回false
*   3.再遍历s，若map[s[i]]构成的字符串s1与t不同，则返回false，否则返回true 
*  
*/
// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        if(sSize != tSize ) return false;
        
        map<char,char> hashTable;
        for(int i=0; i<sSize; ++i){
            if(!hashTable[s[i]])
                hashTable[s[i]] = t[i];
        }
        if(hasDuplicateMap(hashTable))
            return false;

        string s1;
        for(auto ch : s){
            s1 += hashTable[ch];
        }
        return s1 == t ? true : false;
    }
    bool hasDuplicateMap(map<char, char> &hashTable){
        set<char> valueSet;
        for(auto it = hashTable.begin(); it!=hashTable.end(); ++it){
            valueSet.insert(it->second);
        }
        return valueSet.size() != hashTable.size() ? true : false;
    }
};
// @lc code=end

