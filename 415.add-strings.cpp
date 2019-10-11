/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (44.81%)
 * Likes:    520
 * Dislikes: 178
 * Total Accepted:    117.4K
 * Total Submissions: 261.8K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

/*
*   思路：
*   用string表示的两个大数相加
*   1.用carry保存进位，初始值为0
*   2.对num1和num2从后向前遍历，取出来的位分别即为n1和n2，计算n1+n2+carry，若结果>=10，则carry = 1
*
*/
// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1Size = num1.size(), num2Size = num2.size();
        int carry = 0;  string result;

        int i=num1Size-1, j=num2Size-1;
        for(; i>=0 && j>=0; --i, --j){
            int n1 = num1[i] - '0';
            int n2 = num2[j] - '0';
            int n = 0;

            carry = (n = n1 + n2 + carry) >= 10 ? 1 : 0;
            result.insert(result.begin(), (n%10) +'0');
        }
        if(i>j){    //num2遍历完了，num1还有位没有计算
            for(; i>=0; --i){
                int currentBit = num1[i] - '0';
                int n = 0;
                carry = (n = currentBit + carry) >= 10 ? 1 : 0;
                result.insert(result.begin(), (n%10) + '0');
            }
        }
        else if(i<j){
            for(;j>=0; --j){
                int currentBit = num2[j] - '0';
                int n = 0;
                carry = (n = currentBit + carry) >= 10 ? 1 : 0;
                result.insert(result.begin(), (n%10) + '0');
            }
        }
        if(carry>0) result.insert(result.begin(), '1');
        return result;
    }
};
// @lc code=end

