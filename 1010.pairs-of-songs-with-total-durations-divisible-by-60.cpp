/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 *
 * https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
 *
 * algorithms
 * Easy (46.25%)
 * Likes:    259
 * Dislikes: 23
 * Total Accepted:    18.9K
 * Total Submissions: 40.7K
 * Testcase Example:  '[30,20,150,100,40]'
 *
 * In a list of songs, the i-th song has a duration of time[i] seconds. 
 * 
 * Return the number of pairs of songs for which their total duration in
 * seconds is divisible by 60.  Formally, we want the number of indices i < j
 * with (time[i] + time[j]) % 60 == 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [30,20,150,100,40]
 * Output: 3
 * Explanation: Three pairs have a total duration divisible by 60:
 * (time[0] = 30, time[2] = 150): total duration 180
 * (time[1] = 20, time[3] = 100): total duration 120
 * (time[1] = 20, time[4] = 40): total duration 60
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [60,60,60]
 * Output: 3
 * Explanation: All three pairs have a total duration of 120, which is
 * divisible by 60.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= time.length <= 60000
 * 1 <= time[i] <= 500
 * 
 */

/*
*   思路：
*   1.双指针，初试值i指向0，j指向i+1
*   2.循环遍历，若(time[i] + time[j]) % 60 == 0，则计数器+1
*   3.返回计数器值
*/
// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int timeLength = time.size();
        if(timeLength < 1 || timeLength > 60000)  return -1;
        int counter = 0; 
        for(int i=0; i<timeLength; ++i){
            for(int j=i+1; j<timeLength; ++j)
                if( (time[i] + time[j]) % 60 == 0)
                    counter++;  
        }
        return counter;
    }
};
// @lc code=end

