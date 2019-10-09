/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.93%)
 * Likes:    1312
 * Dislikes: 449
 * Total Accepted:    273.7K
 * Total Submissions: 914.5K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */

// @lc code=start
#include <math.h>
class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;

        int count = 0;
        for(int i=2; i<n; ++i){
            if(isPrime(i))
                count++;
        }
        return count;
    }

    bool isPrime(int n){
        for(int i=2; i<=sqrt(double(n)); ++i){
            if(n%i==0)
                return false;
        }
        return true;
    }
};
// @lc code=end

