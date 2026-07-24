// Created by Gavin at 2025/12/14 09:09
// leetgo: 1.4.15
// https://leetcode.cn/problems/subsets/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
   vector<int> t;
   vector<vector<int>> ans;
   vector<vector<int>> subsets(vector<int>& nums) {
     int n = nums.size();
     for (int mask = 0; mask < (1 << n); ++mask) {
       t.clear();
       for (int i = 0; i < n; ++i) {
         if (mask & (1 << i)) {
           t.push_back(nums[i]);
         }
       }
       ans.push_back(t);
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

	Solution *obj = new Solution();
	auto res = obj->subsets(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
