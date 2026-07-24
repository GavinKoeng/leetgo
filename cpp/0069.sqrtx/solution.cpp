// Created by Gavin at 2025/12/11 12:33
// leetgo: 1.4.15
// https://leetcode.cn/problems/sqrtx/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int mySqrt(int x) {
		if (x == 0) {
				return 0;
		}
		int ans = exp(0.5 * log(x));
		return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int x;
	LeetCodeIO::scan(cin, x);

	Solution *obj = new Solution();
	auto res = obj->mySqrt(x);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
