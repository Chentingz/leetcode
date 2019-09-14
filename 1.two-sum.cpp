/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    int seqSearch(vector<int>& nums, int startSearchIndex, int searchNum){
        for(int i=startSearchIndex; i < nums.size(); ++i)
        {
            if(nums[i] == searchNum)
            {
                return i;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        int searchNum;
        for(int i=0; i<nums.size(); ++i)
        {
            searchNum = target;
            searchNum -= nums[i];
            int index=-1;
            if((index = seqSearch(nums, i+1, searchNum))!=-1)
            {
                indices.push_back(i);
                indices.push_back(index);
            }
        }
        return indices;
    }
    
};

