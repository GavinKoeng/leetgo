// Created by Gavin at 2026/01/14 12:23
// leetgo: 1.4.15
// https://leetcode.cn/problems/coin-change-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 使用 unsigned long long 确保不溢出
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }

        return (int)dp[amount];
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int amount;
	LeetCodeIO::scan(cin, amount);
	vector<int> coins;
	LeetCodeIO::scan(cin, coins);

	Solution *obj = new Solution();
	auto res = obj->change(amount, coins);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
