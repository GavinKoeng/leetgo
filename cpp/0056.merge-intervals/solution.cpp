// Created by Gavin at 2025/12/13 13:56
// leetgo: 1.4.15
// https://leetcode.cn/problems/merge-intervals/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
          return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
          int L = intervals[i][0], R = intervals[i][1];
          if (!merged.size() || merged.back()[1] < L) {
            merged.push_back({L, R});
          } else {
            merged.back()[1] = max(merged.back()[1], R);
          }
        }
        return merged;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> intervals;
	LeetCodeIO::scan(cin, intervals);

	Solution *obj = new Solution();
	auto res = obj->merge(intervals);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
