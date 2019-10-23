/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (45.44%)
 * Likes:    567
 * Dislikes: 181
 * Total Accepted:    230.9K
 * Total Submissions: 506.4K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

/*
*   思路：递归
*   1.k=0，返回[1]；k=1，返回[1,1]
*   2.k>1，getRow(k-1)得到上一行的序列pre，根据pre[i] + pre[i+1]得到下一行cur[i+1]
*   
*/
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)    return vector<int>(1,1); 
        if(rowIndex==1)    return vector<int>(2,1);

        vector<int> pre = getRow(rowIndex-1);
        vector<int> cur;
        cur.push_back(1);
        for(int i=0; i<pre.size()-1; ++i){
            cur.push_back(pre[i] + pre[i+1]);
        }
        cur.push_back(1);
        return cur;

    }
};
// @lc code=end

