/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 *
 * https://leetcode.com/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (35.19%)
 * Likes:    205
 * Dislikes: 51
 * Total Accepted:    28.9K
 * Total Submissions: 82.3K
 * Testcase Example:  '[2,1]'
 *
 * Given an array A of integers, return true if and only if it is a valid
 * mountain array.
 * 
 * Recall that A is a mountain array if and only if:
 * 
 * 
 * A.length >= 3
 * There exists some i with 0 < i < A.length - 1 such that:
 * 
 * A[0] < A[1] < ... A[i-1] < A[i] 
 * A[i] > A[i+1] > ... > A[A.length - 1]
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,1]
 * Output: false
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,5,5]
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [0,3,2,1]
 * Output: true
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
/*
*   思路：naive算法
*   1.找到数组中最大值A[i]
*   2.判断A[0] - A[i]是否严格递增
*   3.判断A[i] - A[A.length-1]是否严格递减
*   4.若2.3判断均为true，则返回true
*   
*   时间复杂度：O(n)
*/
// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int ALength = A.size();
        if(ALength < 3) return false;

        int maxIndex = getMaxElementIndex(A, ALength);
        if(isStrictlyIncreasing(A, 0, maxIndex) && isStrictlyDecreasing(A, maxIndex, ALength-1))
            return true;
        return false;
    }
    int getMaxElementIndex(vector<int>& A, int length){
        int max = INT_MIN;
        int maxIndex = -1;
        for(int i=0; i<length; ++i){
            if(max < A[i]){
                max = A[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
    bool isStrictlyIncreasing(vector<int>& A, int startIndex, int endIndex){
        if(startIndex == endIndex) return false;
        for(int i=startIndex; i<=endIndex-1; ++i){
            if(A[i] >= A[i+1])
                return false;
        }
        return true;
    }
    bool isStrictlyDecreasing(vector<int>& A, int startIndex, int endIndex){
        if(startIndex == endIndex) return false;
        for(int i=startIndex; i<=endIndex-1; ++i){
            if(A[i] <= A[i+1])
                return false;
        }
        return true;
    }
};
// @lc code=end

