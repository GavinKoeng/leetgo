// Created by Gavin at 2026/01/20 09:58
// leetgo: 1.4.15
// https://leetcode.cn/problems/coin-change/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int coin : coins) {
            for (int i = 0; i <= amount; i++) {
                if (coin <= i) dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> coins;
	LeetCodeIO::scan(cin, coins);
	int amount;
	LeetCodeIO::scan(cin, amount);

	Solution *obj = new Solution();
	auto res = obj->coinChange(coins, amount);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
