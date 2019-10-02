/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 *
 * https://leetcode.com/problems/unique-number-of-occurrences/description/
 *
 * algorithms
 * Easy (75.53%)
 * Likes:    42
 * Dislikes: 2
 * Total Accepted:    8.9K
 * Total Submissions: 11.8K
 * Testcase Example:  '[1,2,2,1,1,3]'
 *
 * Given an array of integers arr, write a function that returns true if and
 * only if the number of occurrences of each value in the array is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,2,2,1,1,3]
 * Output: true
 * Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two
 * values have the same number of occurrences.
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,2]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * -1000 <= arr[i] <= 1000
 * 
 * 
 */

// @lc code=start


/*
*   思路1：
*   1.用map存储元素与出现次数的映射
*   2.遍历序列arr，记录每个元素出现次数在map中
*   4.遍历map，将出现次数插入到set中
*   5.比较map和set的个数，相同（说明所有元素出现的次数都不同）则返回true，否则返回false
*
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        if(arr.size() < 1 || arr.size() > 1000) return false;
        map<int, int> occurenceTable;
        for(auto element : arr){
            occurenceTable[element]++;
        }

        set<int> occurrenceSet;
        for(auto iter = occurenceTable.begin(); iter!=occurenceTable.end(); iter++){
            occurrenceSet.insert(iter->second);
        }

        if(occurrenceSet.size() == occurenceTable.size() )
            return true;
        return false;
        
    }
};



/* 
*   与思路1基本一样，同样使用map和set进行处理，只有最后判别true或false的条件不同
*   思路2：
*   1.用map存储元素与出现次数的映射
*   2.遍历序列arr，记录每个元素出现次数在map中
*   4.遍历map，将出现次数插入到set中，若插入失败（set中有重复元素）则返回false
*   5.返回true
*
*/

// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         if(arr.size() < 1 || arr.size() > 1000) return false;
//         map<int, int> occurenceTable;
        
//         for(auto element : arr){
//             if(occurenceTable.find(element) != occurenceTable.end()){
//                 occurenceTable[element]++;
//             }
//             else{
//                 occurenceTable.insert(make_pair(element, 1));
//             }
//         }
//         set<int> occurrenceSet;
//         for(map<int, int>::iterator iter = occurenceTable.begin(); iter!=occurenceTable.end(); iter++){
//             if(occurrenceSet.find(iter->second) == occurrenceSet.end()){
//                 occurrenceSet.insert(iter->second);
//             }
//             else{
//                 return false;
//             }
//         }
//         return true;
//     }
// };
// @lc code=end

