/*
 * @lc app=leetcode id=1170 lang=cpp
 *
 * [1170] Compare Strings by Frequency of the Smallest Character
 *
 * https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/
 *
 * algorithms
 * Easy (61.18%)
 * Likes:    42
 * Dislikes: 95
 * Total Accepted:    8.5K
 * Total Submissions: 13.9K
 * Testcase Example:  '["cbd"]\n["zaaaz"]'
 *
 * Let's define a function f(s) over a non-empty string s, which calculates the
 * frequency of the smallest character in s. For example, if s = "dcce" then
 * f(s) = 2 because the smallest character is "c" and its frequency is 2.
 * 
 * Now, given string arrays queries and words, return an integer array answer,
 * where each answer[i] is the number of words such that f(queries[i]) < f(W),
 * where W is a word in words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: queries = ["cbd"], words = ["zaaaz"]
 * Output: [1]
 * Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so
 * f("cbd") < f("zaaaz").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
 * Output: [1,2]
 * Explanation: On the first query only f("bbb") < f("aaaa"). On the second
 * query both f("aaa") and f("aaaa") are both > f("cc").
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= queries.length <= 2000
 * 1 <= words.length <= 2000
 * 1 <= queries[i].length, words[i].length <= 10
 * queries[i][j], words[i][j] are English lowercase letters.
 * 
 * 
 */

 /*
 *  思路：
 *  1.分别求queries和words的frequency，用两个vector存储，记为qFrequency和wFrequency
 *  2.对wFrequency进行排序
 *  3.遍历qFrequency，在wFrequency中二分查找最后一个大于qFrequency[i]的位置pos
 *  4.基于pos统计qFrequency[i] < wFrequency的个数
 *  时间复杂度：O(m*logn)
 */
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int queriesLength = queries.size();
        int wordsLength = words.size();

        vector<int> qFrequency(queriesLength, 0); vector<int> wFrequency(wordsLength,0);
        vector<int> answers(queriesLength,0);

        for(int i=0; i<queriesLength; ++i){
            qFrequency[i] = f(queries[i]);
        }
        for(int i=0; i<wordsLength; ++i){
            wFrequency[i] = f(words[i]);
        }
        sort(wFrequency.begin(), wFrequency.end());  //排序

        /* 用二分查找在wFrequency中找到第一个比qFrequency[i]大的下标x
        *  wFrequencyLength - x即为qFrequency[i] < wFrequency的个数
        */
        int wFrequencyLength = wFrequency.size();
        for(int i=0; i<qFrequency.size();++i){
            int lower=0,upper=wFrequencyLength-1,mid=0;
            while(lower <= upper){
                mid = (lower + upper) / 2;
                if(qFrequency[i] >= wFrequency[mid])
                    lower = mid+1;
                else if(qFrequency[i] < wFrequency[mid])
                    upper = mid-1;
            }
            answers[i] = wFrequencyLength - lower;
        }
        return  answers;
    }

    //统计str中最小字符出现的次数
    int f(string str){
        if(str.size() < 1) return 0;
        int frequency[26] = {0}; int frequencySize = 26;
        for(int i=0; i<str.size(); ++i){
            frequency[str[i]-'a']++;
        }
        for(int i=0; i<frequencySize; ++i){
            if(frequency[i])
                return frequency[i];
        }
        return 0;
    }
};





 /*
 *  思路：遍历queries，在words里找到符合f(queries[i]) < f(Word)的单词个数
 *  时间复杂度：O(m*n)
 */
// class Solution {
// public:
//     vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
//         //参数合法性检测
//         int queriesLength = queries.size();
//         int wordsLength = words.size();
//         if(queriesLength<1 || queriesLength > 2000 || wordsLength<1 || wordsLength>2000)
//             return vector<int>();
        
//         vector<int> answers(queriesLength,0);
//         for(int i=0; i<queriesLength; ++i){
//             if(queries[i].size()<1 || queries[i].size()>10)
//                 return vector<int>(queriesLength,0);
//             for(int j=0; j<wordsLength; ++j){
//                 if(words[j].size()<1 || words[j].size()>10)
//                     return vector<int>(queriesLength,0);
//                 if(f(queries[i]) < f(words[j]))
//                      answers[i]++;
//             }
//         }
//         return  answers;
//     }
//     //统计str中最小字符出现的次数
//     int f(string str){
//         if(str.size() < 1) return 0;
//         int frequency[26] = {0}; int frequencySize = 26;
//         for(int i=0; i<str.size(); ++i){
//             frequency[str[i]-'a']++;
//         }
//         for(int i=0; i<frequencySize; ++i){
//             if(frequency[i])
//                 return frequency[i];
//         }
//         return 0;
//     }
// };

