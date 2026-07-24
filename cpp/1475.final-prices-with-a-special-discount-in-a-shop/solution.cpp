// Created by Gavin at 2026/01/28 12:13
// leetgo: 1.4.15
// https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int discount = 0;
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    discount = prices[j];
                    break;
                }
            }
                    ans[i] = prices[i] - discount;
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> prices;
	LeetCodeIO::scan(cin, prices);

	Solution *obj = new Solution();
	auto res = obj->finalPrices(prices);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
