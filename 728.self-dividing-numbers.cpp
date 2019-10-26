/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 *
 * https://leetcode.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (71.62%)
 * Likes:    483
 * Dislikes: 260
 * Total Accepted:    98.3K
 * Total Submissions: 136.9K
 * Testcase Example:  '1\n22'
 *
 * 
 * A self-dividing number is a number that is divisible by every digit it
 * contains.
 * 
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 ==
 * 0, and 128 % 8 == 0.
 * 
 * Also, a self-dividing number is not allowed to contain the digit zero.
 * 
 * Given a lower and upper number bound, output a list of every possible self
 * dividing number, including the bounds if possible.
 * 
 * Example 1:
 * 
 * Input: 
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * 
 * 
 * Note:
 * The boundaries of each input argument are 1 .
 * 
 */

/*
*   思路：
*   1.遍历给定范围的所有数，判断是否为自除数
*   时间复杂度：O(n^2)
*
*   naive算法判断是否为自除数
*   1.用%从最低位开始取数bit，若bit!=0且num%bit==0，则重复1，直到取完num所有位数，返回true；否则返回false
*   
*   时间复杂度：O(n)
*/
// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left; i<=right; ++i){
            if(isSelfDividingNumber(i))
                result.push_back(i);
        }
        return result;
    }
    bool isSelfDividingNumber(int num){
        int tmpNum = num;
        int bit;
        while(tmpNum){
            if((bit = tmpNum % 10) && num % bit == 0){
                tmpNum/=10;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

