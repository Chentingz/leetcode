/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (48.21%)
 * Likes:    883
 * Dislikes: 84
 * Total Accepted:    297.2K
 * Total Submissions: 614.2K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
/*
*   思路：杨辉三角
*   1.第i行有i+1个元素，i从0开始
*   2.每一行首尾元素均为1，除首尾之外的其他元素a[i][j] = a[i-1][j-1] + a[i-1][j]
*/
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        for(int i=0; i<triangle.size(); ++i){
            triangle[i].reserve(numRows);
        }
        for(int i=0; i<numRows; ++i){
            if(i==0){
                triangle[i].push_back(1);
            }
            else if(i==1){
                triangle[i].push_back(1);
                triangle[i].push_back(1);
            }
            else{             
                triangle[i].push_back(1);
                for(int j=1; j<=i-1; ++j)
                    triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
                triangle[i].push_back(1);
            }
        }
        return triangle;
    }
};
// @lc code=end

