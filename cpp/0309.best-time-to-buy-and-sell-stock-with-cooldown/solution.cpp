// Created by Gavin at 2026/01/02 13:00
// leetgo: 1.4.15
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i -1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> prices;
	LeetCodeIO::scan(cin, prices);

	Solution *obj = new Solution();
	auto res = obj->maxProfit(prices);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
