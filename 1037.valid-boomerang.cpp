/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 *
 * https://leetcode.com/problems/valid-boomerang/description/
 *
 * algorithms
 * Easy (37.48%)
 * Likes:    53
 * Dislikes: 159
 * Total Accepted:    10.7K
 * Total Submissions: 28.6K
 * Testcase Example:  '[[1,1],[2,3],[3,2]]'
 *
 * A boomerang is a set of 3 points that are all distinct and not in a straight
 * line.
 * 
 * Given a list of three points in the plane, return whether these points are a
 * boomerang.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,3],[3,2]]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * points.length == 3
 * points[i].length == 2
 * 0 <= points[i][j] <= 100
 * 
 * 
 * 
 * 
 * 
 */

/*
*   思路：naive算法
*   1.构造直线ax+by+c=0（一般式）,用两个点计算出a和b, a=y2-y1, b=x2-x1, c=x2*y1-x1*y2
*   2.将第三个点的横坐标x代入直线y=ax+b，计算y'
*   3.若计算结果y'与第三个点的纵坐标y相同，则在一条直线上，返回false;否则返回true
*/
// @lc code=start
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int a=0, b=0, c=0;
        // a=y2-y1, b=x1-x2, c=x2*y1-x1*y2
        a = points[1][1] - points[0][1];
        b = points[0][0] - points[1][0];
        c = points[1][0] * points[0][1] - points[0][0] * points[1][1];
        if(isPointOnStraightLine(a,b,c, points[2]))
            return false;
        return true;
    }
    bool isPointOnStraightLine(int a, int b, int c, vector<int>& point){
        double y = -1.0;
        if(b){
            y *= ((double)(a*point[0] + c) / b);
            return y == point[1] ? true : false;
        }
        else{
            return a*point[0] + c == 0 ? true : false;
        }

        
    }
};
// @lc code=end

