// Created by Gavin at 2025/12/12 15:10
// leetgo: 1.4.15
// https://leetcode.cn/problems/sliding-window-maximum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int n = nums.size();
	   priority_queue<pair<int, int>> q;
	   for (int i = 0; i < k; ++i) {
			   q.emplace(nums[i], i);
	   }
	   vector<int> ans = {q.top().first};
	   for (int i = k; i < n; ++i) {
			   q.emplace(nums[i], i);
			   while (q.top().second <= i - k) {
					   q.pop();
			   }
			   ans.push_back(q.top().first);
	   }
	   return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->maxSlidingWindow(nums, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
