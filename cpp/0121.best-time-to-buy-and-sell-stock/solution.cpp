// Created by Gavin at 2026/01/01 16:32
// leetgo: 1.4.15
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price : prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
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
