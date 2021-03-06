Group Anagrams.cpp
/*


Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

*/

// Time:  O(n * glogg), g is the max size of groups.
// Space: O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const auto& str : strs) {
            string tmp{str};
            sort(tmp.begin(), tmp.end());
            groups[tmp].emplace_back(str);
        }

        vector<vector<string>> anagrams;
        for (const auto& kvp : groups) {
            vector<string> group;
            for (const auto& str : kvp.second) {
                group.emplace_back(str);
            }
            sort(group.begin(), group.end());
            anagrams.emplace_back(move(group));
        }

        return anagrams;
    }
};