// Created by Gavin at 2026/02/01 22:26
// leetgo: 1.4.15
// https://leetcode.cn/problems/longest-palindrome/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        int ans = 0;
        for (char c : s) count[c]++;
        for (auto p : count) {
            int v = p.second;
            ans += v / 2 * 2;
            if (v % 2 == 1 and ans % 2 == 0) ans++;
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
	auto res = obj->longestPalindrome(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
