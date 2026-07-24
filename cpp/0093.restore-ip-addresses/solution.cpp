// Created by Gavin at 2025/12/17 22:28
// leetgo: 1.4.15
// https://leetcode.cn/problems/restore-ip-addresses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    static constexpr int SEG_COUNT = 4;

private:
	vector<string> ans;
	vector<int> segments;

public:
	void dfs(const string& s, int segId, int segStart) {
        if (segId == SEG_COUNT) {
				if (segStart == s.size()) {
						string ipAddr;
						for (int i = 0; i < SEG_COUNT; ++i) {
								ipAddr += to_string(segments[i]);
								if (i != SEG_COUNT - 1) {
										ipAddr += ".";
								}
						}
						ans.push_back(move(ipAddr));
				}
				return;
		}

		if (segStart == s.size()) {
				return;
		}

		if (s[segStart] == '0') {
				segments[segId] = 0;
				dfs(s, segId + 1, segStart + 1);
				return;
		}

		int addr = 0;
		for (int segEnd = segStart; segEnd < s.size(); ++segEnd) {
				addr = addr * 10 + (s[segEnd] - '0');
				if (addr > 0 && addr <= 0xFF) {
						segments[segId] = addr;
						dfs(s, segId + 1, segEnd + 1);
				} else {
						break;
				}
		}
	}

    vector<string> restoreIpAddresses(string s) {
		segments.resize(SEG_COUNT);
		dfs(s, 0, 0);
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
	auto res = obj->restoreIpAddresses(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
