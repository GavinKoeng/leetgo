// Created by Gavin at 2025/12/08 14:52
// leetgo: 1.4.15
// https://leetcode.cn/problems/4sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> quadruplets;
			if (nums.size() < 4) {
					return quadruplets;
			}
			sort(nums.begin(), nums.end());
			int length = nums.size();
			for (int i = 0; i < length - 3; i++) {
					if (i > 0 && nums[i] == nums[i - 1]) {
							continue;
					}
					if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
							break;
					}
					if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
							continue;
					}
					for (int j = i + 1; j < length - 2; j++) {
							if (j > i + 1 && nums[j] == nums[j - 1]) {
									continue;
							}
							if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
									break;
							}
							if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
									continue;
							}
							int left = j + 1, right = length - 1;
							while (left < right) {
									long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
									if (sum == target) {
											quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
											while (left < right && nums[left] == nums[left + 1]) {
													left++;
											}
											left++;
											while (left < right && nums[right] == nums[right - 1]) {
													right--;
											}
											right--;
									} else if (sum < target) {
											left++;
									} else {
											right--;
										}
							}
					}
			}
			return quadruplets;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->fourSum(nums, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
