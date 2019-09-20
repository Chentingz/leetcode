/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 *
 * https://leetcode.com/problems/day-of-the-year/description/
 *
 * algorithms
 * Easy (49.46%)
 * Likes:    40
 * Dislikes: 64
 * Total Accepted:    8.8K
 * Total Submissions: 17.7K
 * Testcase Example:  '"2019-01-09"\r'
 *
 * Given a string date representing a Gregorian calendar date formatted as
 * YYYY-MM-DD, return the day number of the year.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: date = "2019-01-09"
 * Output: 9
 * Explanation: Given date is the 9th day of the year in 2019.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: date = "2019-02-10"
 * Output: 41
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: date = "2003-03-01"
 * Output: 60
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: date = "2004-03-01"
 * Output: 61
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * date.length == 10
 * date[4] == date[7] == '-', and all other date[i]'s are digits
 * date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
 * 
 */
 
 /*
 *  思路：
 *  1.用一个vector数组存储平年1-12月对应的天数 
 *  2.判断当前年是否为闰年，若是，将vector[2]=29并设置闰年标志
 *  3.若当前月不是1月，则返回 求和（1月至当前月的上一个月所有天数）+ 当前日；否则，返回当前日
 *
 */
 #include <stdlib.h>
class Solution {
public:
    int dayOfYear(string date) {
        vector<int> days = {0, 31,28,31,30,31,30,31,31,30,31,30,31};   //初始设置为平年
        bool leapYearFlag = false;
        int year = atoi(date.substr(0,4).c_str());
        int month = atoi(date.substr(5,2).c_str());
        int day = atoi(date.substr(8,2).c_str());
        if(year%4==0 && year%100!=0 || year%400==0){
            leapYearFlag = true;
            days[2] = 29;
        }
        int sum = 0;
        for(int i=1; i<=month-1; ++i){
            sum += days[i];
        }
       sum += day;
       return sum;
    }
};

