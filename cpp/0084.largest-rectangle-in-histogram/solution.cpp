// Created by Gavin at 2026/01/29 00:20
// leetgo: 1.4.15
// https://leetcode.cn/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector <int> left(n), right(n);
        stack <int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = (s.empty() ? -1 : s.top());
            s.push(i);
        }

        s = stack <int> ();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = (s.empty() ? n : s.top());
            s.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> heights;
	LeetCodeIO::scan(cin, heights);

	Solution *obj = new Solution();
	auto res = obj->largestRectangleArea(heights);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
