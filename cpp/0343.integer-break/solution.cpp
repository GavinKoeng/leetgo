// Created by Gavin at 2026/01/03 15:29
// leetgo: 1.4.15
// https://leetcode.cn/problems/integer-break/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            int curMax = 0;
            for (int j = 1; j < i; ++j) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	auto res = obj->integerBreak(n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
