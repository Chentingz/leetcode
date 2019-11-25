/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.82%)
 * Likes:    1149
 * Dislikes: 7096
 * Total Accepted:    435.2K
 * Total Submissions: 2.9M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "42"
 * Output: 42
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical 
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * 
 * Example 5:
 * 
 * 
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 * 
 */

/*
*   算法：
*   1.遍历字符串，找到第一个非空格非字母字符，判断其是数字或'-'
*   2.若是'-'，将符号位sign = -1
*   3.若是数字，则转换成数字bit = str[i] - '0',试探result = result*10 + bit是否超过int的表示范围，若超过返回INT_MAX或INT_MIN，否则，跳5
*   5.跳3，直到当前字符不是数字
*   6.根据符号位调整result的符号
*   7.返回result

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, result = 0, tmp = 0, i=0;
        for(; i<str.size(); ++i){
           // if(str[i] == '-' && i != str.size()-1 && str[i+1] >= '0' && str[i+1] <= '9'){
            if(str[i] == '-'){
                sign = -1;
                ++i;
                break;
            }
            else if(str[i] >= '0' && str[i] <= '9'){
                result = result*10 + str[i] - '0';
                ++i;
                break;
            }
        }
        // 没找到'-'或数字
        if(i == str.size())
            return 0;

        while(i<str.size()){
            if( str[i] >= '0' && str[i] <= '9' && (tmp = result*10 + str[i] - '0') > INT_MAX / 10)
                return INT_MAX; 
            else if(tmp*sign < INT_MIN)
                return INT_MIN;
            else
                result = tmp;
            
            if(i+1 < str.size() && str[i+1] >= '0' && str[i+1] <= '9')
                ++i;
            else
                break;
        }
        return result *= sign;
        
        
    }
};
*/
// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0) return 0;
        int i = 0;
        // Find first non-whitespace char
        for(; i<str.size(); ++i){
            if(str[i] != ' ')
                break;
        }
        if(i==str.size()) return 0; // all chars are whitespace
        // determin positive or negative flag
        bool negativeFlag = false;
        if(i+1<str.size() && str[i] == '-' && str[i+1]>='0' && str[i+1]<='9'){
            negativeFlag = true;
            ++i;
        }
        else if(i+1<str.size() && str[i] == '+' && str[i+1]>='0' && str[i+1]<='9'){
            negativeFlag = false;
            ++i;
        }
        // first non-whitespace char is not numerical value    
        else if(str[i]<'0' || str[i]>'9')
            return 0;
        
        string numstr = "";
        // get numericsl value as much as possible
        for(;i<str.size();++i){
            if(str[i]<'0' || str[i]>'9')
              break;
            numstr += str[i];
        }
        // find first non-zero char
        string numstr1 = "";
        int j=0;
        for(;j<numstr.size();++j){
            if(numstr[j]!='0'){
                numstr1 = numstr.substr(j);
                break;
            }
        }
        if(j==numstr.size()) // all chars are zero
            return 0;
        
        // out of range
        string intmaxstr= "";
        int intmax= INT_MAX;
        while(intmax){
            intmaxstr += intmax%10 +'0';
            intmax /=10;
        }
        
        if(numstr1.size() > intmaxstr.size())
           return negativeFlag ? INT_MIN : INT_MAX;
        else if (numstr1.size() == intmaxstr.size()){
           double num = 0;
           for(auto ch : numstr1){
               num = num*10 + ch-'0';
           }
           if(negativeFlag) num*= -1;
           return num > INT_MAX ? INT_MAX : num < INT_MIN ? INT_MIN : num;
        }
        // within range
        int num=0;
        for(auto ch : numstr1){
            num = num*10 + ch-'0';
        }
        if(negativeFlag) num*= -1;
        return num;
        
    }
};
// @lc code=end

