// Created by Gavin at 2025/12/05 13:44
// leetgo: 1.4.15
// https://leetcode.cn/problems/remove-k-digits/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string removeKdigits(string num, int k) {
		vector<char> stk;
		for (auto& digit: num) {
				while (stk.size() > 0 && stk.back() > digit && k) {
						stk.pop_back();
						k -= 1;
				}
				stk.push_back(digit);
		}

		for (; k > 0; --k) {
				stk.pop_back();
		}

		string ans = "";
		bool isLeadingZero = true;
		for (auto& digit: stk) {
				if (isLeadingZero && digit == '0') {
						continue;
				}
				isLeadingZero = false;
				ans += digit;
		}
		return ans == "" ? "0" : ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string num;
	LeetCodeIO::scan(cin, num);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->removeKdigits(num, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
