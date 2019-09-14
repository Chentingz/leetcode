/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.49%)
 * Likes:    2426
 * Dislikes: 3772
 * Total Accepted:    799.2K
 * Total Submissions: 3.1M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
        // if(!checkRangeOfInteger(x))
        //     return 0;
        int reverse = 0;            // 保存反转的结果
        int modResult=0;            // 保存mod10的结果
        int divideResult=x;         // 保存除10的结果
        bool negativeFlag = false;  // 负数标志
        // if(divideResult < 0){
        //      negativeFlag = true;
        //      if(!checkRangeOfInteger(-divideResult))
        //         return 0;
        //      divideResult = -divideResult;  // 负数先转成正数处理
        // }
           
        while(divideResult){
            modResult = divideResult % 10;
            if(!checkRangeOfInteger(reverse))
              return 0;
            else{
                reverse = reverse*10 + modResult;
                divideResult /= 10;
            }
        }
        // if(negativeFlag){
        //     reverse = -reverse;
        // }
            return reverse;
    }
    bool checkRangeOfInteger(int x){
        if(x < INT_MIN/10 || x > INT_MAX/10)
            return false;               // 越界
        else 
            return true;
    }
};

