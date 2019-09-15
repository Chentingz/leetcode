/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (32.86%)
 * Likes:    1033
 * Dislikes: 1487
 * Total Accepted:    489.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackSize = haystack.size();
        int needleSize = needle.size();
        if(needle.empty() || haystack == needle)
            return 0;
        if(needleSize > haystackSize)
            return -1;

        for(int i=0; i<=(haystackSize - needleSize); ++i){
          //  if(haystack[i] == needle[0] && match(haystack.substr(i), needle))
            if(haystack[i] == needle[0]){
                int j=0;
                for(; j<needleSize; ++j){
                    if(haystack[i+j] != needle[j])
                        break;
                }
                if(j == needleSize)
                    return i;
            }
            
        }
        return -1;
    }
    // bool match(const string& haystack, const string& needle){
    //     // int countEqualSize = 0;
    //     int needleSize = needle.size();
    //     int i=0;
    //     for(; i<needleSize; ++i) {
    //         if(haystack[i] != needle[i]){
    //             break;
    //         }
    //         // countEqualSize++;
    //     }   
    //     // if(countEqualSize == needleSize)
    //     if(i == needleSize)
    //         return true;
    //     return false;
    // }

};
