// Created by Gavin at 2025/12/05 15:07
// leetgo: 1.4.15
// https://leetcode.cn/problems/3sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		// 枚举
		for (int first = 0; first < n; ++first) {
				// 需要和上一次枚举的数不相同
				if (first > 0 && nums[first] == nums[first - 1]) {
								continue;
				}
				// c 对应的指针初始指向数组的最右端
				int third = n - 1;
				int target = -nums[first];
				// 枚举 b
				for (int second = first + 1; second < n; ++second) {
						// 需要和上一次枚举的数不相同
						if (second > first + 1 && nums[second] == nums[second - 1]) {
							continue;
						}
						// 需要保证 b 的指针在 c 的指针的左侧
						while (second < third && nums[second] + nums[third] > target) {
							--third;
						}
						// 如果指针重合，随着 b 后续的增加
						// 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
						if (second == third) {
							break;
						}
						if (nums[second] + nums[third] == target) {
							ans.push_back({nums[first], nums[second], nums[third]});
						}
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
	auto res = obj->threeSum(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
