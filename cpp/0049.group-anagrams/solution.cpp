// Created by Gavin at 2026/02/05 10:36
// leetgo: 1.4.15
// https://leetcode.cn/problems/group-anagrams/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ num;
            });
        };
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str : strs) {
            int length = str.length();
            array<int, 26> counts{};
            for (int i = 0; i < length; i++) {
                counts[str[i] - 'a']++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> strs;
	LeetCodeIO::scan(cin, strs);

	Solution *obj = new Solution();
	auto res = obj->groupAnagrams(strs);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
