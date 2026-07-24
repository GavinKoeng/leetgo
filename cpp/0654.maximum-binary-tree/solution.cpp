// Created by Gavin at 2025/12/24 00:56
// leetgo: 1.4.15
// https://leetcode.cn/problems/maximum-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      return construct(nums, 0, nums.size() - 1);
    }

    TreeNode* construct(const vector<int>& nums, int left, int right) {
      if (left > right) {
        return nullptr;
      }
      int best = left;
      for (int i = left + 1; i <= right; ++i) {
        if (nums[i] > nums[best]) {
          best = i;
        }
      }
      TreeNode* node = new TreeNode(nums[best]);
      node->left = construct(nums, left, best - 1);
      node->right = construct(nums, best + 1, right);
      return node;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->constructMaximumBinaryTree(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
