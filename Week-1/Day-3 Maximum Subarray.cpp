Maximum Subarray.cpp

/*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


*/





class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const auto& max_num = *max_element(nums.cbegin(), nums.cend());
        if (max_num < 0) {
            return max_num;
        }
        int global_max = 0, local_max = 0;
        for (const auto &x : nums) {
           local_max = std::max(0, local_max + x);
           global_max = std::max(global_max, local_max);
        }
        return global_max;
    }
};