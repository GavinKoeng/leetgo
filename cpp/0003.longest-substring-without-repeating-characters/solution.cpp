// Created by Gavin at 2025/12/12 10:38
// leetgo: 1.4.15
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
		int n = s.size();
		int rk = -1, ans = 0;
		for (int i = 0; i < n; ++i) {
				if (i != 0) {
						occ.erase(s[i - 1]);
				}
				while (rk + 1 < n && !occ.count(s[rk + 1])) {
						occ.insert(s[rk + 1]);
						++rk;
				}
				ans = max(ans, rk - i + 1);
		}
		return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->lengthOfLongestSubstring(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
