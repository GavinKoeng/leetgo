// Created by Gavin at 2025/12/14 00:38
// leetgo: 1.4.15
// https://leetcode.cn/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int quickselect(vector<int> &nums, int l, int r, int k) {
      if (l == r){
        return nums[k];
      }
      int partition = nums[l], i = l - 1, j = r + 1;
      while (i < j) {
        do i++; while (nums[i] < partition);
        do j--; while (nums[j] > partition);
        if (i < j) 
          swap(nums[i], nums[j]);
      }
      if (k <= j) return quickselect(nums, l, j, k);
      else return quickselect(nums, j + 1, r, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
       int n = nums.size();
       return quickselect(nums, 0, n - 1, n - k);
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
	auto res = obj->findKthLargest(nums, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
