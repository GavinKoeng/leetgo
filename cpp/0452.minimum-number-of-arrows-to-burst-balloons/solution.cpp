// Created by Gavin at 2025/12/04 11:14
// leetgo: 1.4.15
// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       if (points.empty()) {
			   return 0;
	   }
	   sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
					   return u[1] < v[1];
					   });
	   int pos = points[0][1];
	   int ans = 1;
	   for (const vector<int>& balloon: points) {
			   if (balloon[0] > pos) {
					   pos = balloon[1];
					   ++ans;
			   }
	   }
	   return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> points;
	LeetCodeIO::scan(cin, points);

	Solution *obj = new Solution();
	auto res = obj->findMinArrowShots(points);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
