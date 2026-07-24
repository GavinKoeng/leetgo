// Created by Gavin at 2025/12/14 09:31
// leetgo: 1.4.15
// https://leetcode.cn/problems/subsets-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
   vector<int> t;
   vector<vector<int>> ans;
   vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     int n = nums.size();
     sort(nums.begin(), nums.end());
     for (int mask = 0; mask < (1 << n); ++mask) {
       t.clear();
       bool flag = true;
       for (int i = 0; i < n; ++i) {
         if (mask & (1 << i)) {
           if (i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i - 1]) {
             flag = false;
             break;
           }
           t.push_back(nums[i]);
         }
       }
       if (flag) {
         ans.push_back(t);
       }
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
	auto res = obj->subsetsWithDup(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
