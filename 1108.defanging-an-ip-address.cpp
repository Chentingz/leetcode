/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 *
 * https://leetcode.com/problems/defanging-an-ip-address/description/
 *
 * algorithms
 * Easy (84.22%)
 * Likes:    103
 * Dislikes: 339
 * Total Accepted:    57.5K
 * Total Submissions: 68.3K
 * Testcase Example:  '"1.1.1.1"'
 *
 * Given a valid (IPv4) IP address, return a defanged version of that IP
 * address.
 * 
 * A defanged IP address replaces every period "." with "[.]".
 * 
 * 
 * Example 1:
 * Input: address = "1.1.1.1"
 * Output: "1[.]1[.]1[.]1"
 * Example 2:
 * Input: address = "255.100.50.0"
 * Output: "255[.]100[.]50[.]0"
 * 
 * 
 * Constraints:
 * 
 * 
 * The given address is a valid IPv4 address.
 * 
 */

 /*
 *  思路：用辅助空间存储新的地址
 */
class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for(int i=0; i<address.size(); ++i){
            if(address[i] == '.')
                result.append("[.]");
            else
                result.push_back(address[i]);
        }
        return result;
    }
};

