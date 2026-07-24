// Created by Gavin at 2025/12/12 11:27
// leetgo: 1.4.15
// https://leetcode.cn/problems/minimum-window-substring/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
		unordered_map<char, int> ori, cnt;

		bool check() {
				for (const auto &p: ori) {
						if (cnt[p.first] < p.second) {
								return false;
						}
				}
				return true;
		}

		string minWindow(string s, string t) {
				for (const auto &c: t) {
						++ori[c];
				}

				int l = 0, r = -1;
				int len = INT_MAX, ansL = -1;

				while (r < int(s.size())) {
						if (ori.find(s[++r]) != ori.end()) {
								++cnt[s[r]];
						}
						while (check() && l <= r) {
								if (r - l + 1 < len) {
										len = r - l + 1;
										ansL = l;
								}
								if (ori.find(s[l]) != ori.end()) {
										--cnt[s[l]];
								}
								++l;
						}
				}
		return ansL == -1 ? string() : s.substr(ansL, len);
		}
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);
	string t;
	LeetCodeIO::scan(cin, t);

	Solution *obj = new Solution();
	auto res = obj->minWindow(s, t);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
