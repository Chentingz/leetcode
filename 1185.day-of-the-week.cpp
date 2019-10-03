/*
 * @lc app=leetcode id=1185 lang=cpp
 *
 * [1185] Day of the Week
 *
 * https://leetcode.com/problems/day-of-the-week/description/
 *
 * algorithms
 * Easy (65.78%)
 * Likes:    17
 * Dislikes: 253
 * Total Accepted:    6.7K
 * Total Submissions: 10.1K
 * Testcase Example:  '31\n8\n2019'
 *
 * Given a date, return the corresponding day of the week for that date.
 * 
 * The input is given as three integers representing the day, month and year
 * respectively.
 * 
 * Return the answer as one of the following values {"Sunday", "Monday",
 * "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: day = 31, month = 8, year = 2019
 * Output: "Saturday"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: day = 18, month = 7, year = 1999
 * Output: "Sunday"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: day = 15, month = 8, year = 1993
 * Output: "Sunday"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The given dates are valid dates between the years 1971 and 2100.
 * 
 */

 /*
 *  思路：
 *  如果x年是平年，则x+1年的1月1日对应的星期几+1，否则x+1年的1月1日对应的星期几+2
 *  1.求出这一年的1月1号是星期几jan1stOffset
 *  2.求出当前日与1月1号之间的偏移量offset
 *  3.((offset % 7) + jan1stOffset )% 7即为所求
 *
 *  周日 周一 周二 周三 周四 周五 周六
 *    0   1   2    3    4   5    6  
 */
 
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        if(year<1971 || year>2100)  return NULL;
        // 1971.1.1 周五

        // 求当前年的1月1日对应是星期几
        int jan1stOffSet = 5;           //初始值设为1971年1月1日的周五
        bool lastYearIsLeapYear = false;
        if(year!=1971){
            for(int i=1972; i<=year; ++i){
                if(lastYearIsLeapYear){
                    lastYearIsLeapYear = false;
                    jan1stOffSet = (jan1stOffSet + 2) % 7;
                }
                else{
                    jan1stOffSet = (jan1stOffSet + 1) % 7;
                }
                if(leapYear(i)){
                    lastYearIsLeapYear = true;
                }
            }
        }

        int daysOfTheMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(leapYear(year))  daysOfTheMonth[2] = 29;
        // 求当前日期对应是星期几
        int daysOfTheYear = 0;
        for(int i=1; i<month; ++i){
            daysOfTheYear += daysOfTheMonth[i];
        }
        daysOfTheYear += day;
        int daysOfTheWeek = ((daysOfTheYear % 7) + jan1stOffSet-1) % 7;
        
        map<int,string> week={{0,"Sunday"}, {1,"Monday"}, {2,"Tuesday"}, {3,"Wednesday"}, {4,"Thursday"}, {5,"Friday"}, {6, "Saturday"}};
        return week[daysOfTheWeek];

    }
    bool leapYear(int year){
        return year%400==0 || year%4==0 && year%100!=0 ? true : false;
    }
};

