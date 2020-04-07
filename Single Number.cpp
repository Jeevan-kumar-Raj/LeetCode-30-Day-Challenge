 Single Number.cpp
 /*
 Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/
 // Time:  O(n)
// Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(),
                          0, std::bit_xor<int>());
    }
};
