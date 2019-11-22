/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.47%)
 * Likes:    1271
 * Dislikes: 3806
 * Total Accepted:    382.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

// @lc code=start
/*
*   方法1.模拟行指针移动来置放字符
*   思路：
*   - 遍历字符串，在zigzag矩阵(vector<string>表示)中寻找合适的行插入字符
*   - zigzag扫描，行指针row的移动范围为[0, numRows-1]
*   - 从第0行开始向下移动，当到达numRows-1行时，指针row开始向上移动，当到达0时，又向下移动

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <=0 || s.size() == 0) return "";
        if(numRows == 1)    return s;
        vector<string> zigzagMatrix(numRows);
        int row = 0;
        int step = 1;
        // 构造zigzag矩阵
        for(char ch : s){
            if(row == 0)
                step = 1;
            else if(row == numRows-1)
                step = -1;
            zigzagMatrix[row] += ch;
            row += step;
        }
        string result = "";
        for(string str : zigzagMatrix){
            result += str;
        }

        return result;
    }
};
*/
/*
*   方法2.按照zigzag扫描的顺序依次置放字符，构造zigzag矩阵，然后按行读取非空字符存储到字符串result中
*   思路：
*   - 先列后行的顺序寻找插入位置
*   - col % (numRows-1) == 0 ：col列所有行都可以插入
*   - col % (numRows-1) != 0 ：col列只有（numRows-col）行可以插入字符
*   - 例如：
*   -    0 1 2 3 4 5 6 
*   - 0  P   A   H   N
*   - 1  A P L S I I G
*   - 2  Y   I   R
*   - 第1列只有(3-1) = 2行可以插入字符
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <=0 || s.size() == 0) return "";
        if(numRows == 1)    return s;
        vector<vector<char>> zigzagMatrix(numRows, vector<char>(s.size()));

        // 构造zigzag矩阵
        int i=0;
        bool allCharVisited = false;
        for(int col=0; col < zigzagMatrix[0].size(); ++col){
            // 全部行都可以插入
            if(col% (numRows-1) == 0){
                for(int row=0; row <zigzagMatrix.size(); ++row){
                    zigzagMatrix[row][col] = s[i++];
                    if(i == s.size()){
                        allCharVisited = true;
                        break;
                    }

                }
            }
            // 只能插入指定行
            else{
                if(numRows-col < 0 || numRows-col >= numRows) break;
                zigzagMatrix[numRows-col][col] = s[i++];
                if(i == s.size())
                    allCharVisited = true;
            }
            if(allCharVisited)
                break;
        }       
        // 按行读取非空字符存储在字符串str中返回
        string result="";
        for(int i=0; i<zigzagMatrix.size(); ++i){
            for(int j=0; j<zigzagMatrix[i].size(); ++j){
                if(zigzagMatrix[i][j] != ' ')
                    result += zigzagMatrix[i][j];
            }
        }
        return result;
     }
};
// @lc code=end

