// Created by Gavin at 2025/12/04 13:55
// leetgo: 1.4.15
// https://leetcode.cn/problems/non-overlapping-intervals/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
			if (intervals.empty()) {
					return 0;
			}

			sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
							return u[1] < v[1];
							});
			
			int n = intervals.size();
			int right = intervals[0][1];
			int ans = 1;
			for (int i = 1; i < n; ++i) {
					if (intervals[i][0] >= right) {
							++ans;
							right = intervals[i][1];
					}
			}
			return n - ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> intervals;
	LeetCodeIO::scan(cin, intervals);

	Solution *obj = new Solution();
	auto res = obj->eraseOverlapIntervals(intervals);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
