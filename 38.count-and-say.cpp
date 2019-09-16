/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (41.69%)
 * Likes:    893
 * Dislikes: 6978
 * Total Accepted:    314.3K
 * Total Submissions: 753.3K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
public:
string countAndSay(int n) {
       if(n<1||n>30) return string("");
        if(n==1)     return "1";
        string result("1");
        for(int i=2;i<=n;++i){
            result = countAndSay(result);
        }
        return result;
    }
    // 给一个序列，得到下一阶序列，如Input:2,1,Output:1,2,1,1
    string countAndSay(string seq){
        int i=0,j;
        int counter=0;
        string result;
        while(i<seq.size()){
            counter=1;
            // count the same element in the subsequence,element should be continuous
            for(j=i+1;j<seq.size();++j){
                if(seq[j]!=seq[i])
                    break;
                counter++;
            }
            result.insert(result.end(),counter+'0');
            result.insert(result.end(),seq[i]);
            i=j;
        }
        return result;
    }
};

