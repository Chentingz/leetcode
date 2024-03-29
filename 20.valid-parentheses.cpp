/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.22%)
 * Likes:    3330
 * Dislikes: 154
 * Total Accepted:    690.4K
 * Total Submissions: 1.9M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        if(s.size() == 1) return false;

        stack<char> myStack;
        int i=0;
        while(i<s.size()){
            if(myStack.empty())
                myStack.push(s[i]);
            else
                isPaired(myStack.top(), s[i]) ? myStack.pop() : myStack.push(s[i]);
            i++;
        }
        return myStack.empty() ? true : false;
    }
    bool isPaired(char x, char y){
        map<char,char> pairTable = { {'(', ')'}, {'[', ']'}, {'{', '}'} };
        return pairTable[x] == y ? true : false;
    }
};

