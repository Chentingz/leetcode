/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.65%)
 * Likes:    982
 * Dislikes: 1746
 * Total Accepted:    442.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * Custom Example:
 * 
 * 
 * Input: [9,9,9]
 * Output: [1,0,0,0]
 *
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits);
        int i=digits.size()-1;  int carry =1;
        while(i>=0){
            if(digits[i]+carry>9){
                result[i]=0;
                carry=1;
                --i;
            }
            else{
                result[i]=(digits[i]+1);
                carry=0;
                break;
            }
        }
        if(carry==1&&i==-1)
            result.insert(result.begin(),carry);
        return result;
    }
};

