// Created by Gavin at 2026/01/20 10:29
// leetgo: 1.4.15
// https://leetcode.cn/problems/corporate-flight-bookings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);
        for (auto& booking : bookings) {
            nums[booking[0] - 1] += booking[2];
            if (booking[1] < n) {
                nums[booking[1]] -= booking[2];
            }
        }
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> bookings;
	LeetCodeIO::scan(cin, bookings);
	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	auto res = obj->corpFlightBookings(bookings, n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
