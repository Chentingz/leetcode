/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] carry Binary
 *
 * https://leetcode.com/problems/carry-binary/description/
 *
 * algorithms
 * Easy (40.47%)
 * Likes:    1142
 * Dislikes: 219
 * Total Accepted:    336.9K
 * Total Submissions: 832K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string carryBinary(string a, string b) {
        int sum = 0;    // 保存按位相加的结果
        int carry = 0;    // 保存进位，取值0或1
      
        string result;
        int i=a.size()-1, j=b.size()-1;
        for(; i>=0 && j>=0; --i,--j){
            sum = a[i]-'0' + b[j]-'0' + carry;
            if(sum == 0 || sum == 1){
                carry = 0;
            }
            if(sum == 2){
                sum = 0;
                carry = 1;
            }
            if(sum == 3){
                sum = 1;
                carry = 1;
            }
            // sum==0 ? result.insert(0,1, '0') : result.insert(0,1,'1');
                            sum == 0 ? result= '0'+result : result = '1'+result;
        }
        if(i<0){
            for(; j>=0; --j){
                sum = b[j]-'0' + carry;
                if(sum == 0 || sum == 1){
                    carry = 0;
                }
                if(sum == 2){
                    sum = 0;
                    carry = 1;
                }
                if(sum == 3){
                    sum = 1;
                    carry = 1;
                }
                // sum==0 ? result.insert(0,1, '0') : result.insert(0,1,'1');
                                sum == 0 ? result= '0'+result : result = '1'+result;
            }  
        }
        if(j<0){
            for(; i>=0; --i){
                sum = a[i]-'0' + carry;
                if(sum == 0 || sum == 1){
                    carry = 0;
                }
                if(sum == 2){
                    sum = 0;
                    carry = 1;
                }
                if(sum == 3){
                    sum = 1;
                    carry = 1;
                }
                //sum==0 ? result.insert(0,1, '0') : result.insert(0,1,'1');
                sum == 0 ? result= '0'+result : result = '1'+result;
            }
        }
        if(carry == 1)
            // result.insert(0,1, '1');
            result = '1'+result;
        return result;
    }

};

