// Created by Gavin at 2025/12/05 16:19
// leetgo: 1.4.15
// https://leetcode.cn/problems/3sum-closest/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
		int n = nums.size();
		int best = 1e7;

		// 根据差值的绝对值来更新答案
		auto update = [&](int cur) {
				if (abs(cur - target) < abs(best - target)) {
						best = cur;
				}
		};

		// 枚举a
		for (int i = 0; i < n; ++i) {
				// 保证和上一次枚举的元素不相等
				if (i > 0 && nums[i] == nums[i - 1]) {
						continue;
				}
				// 使用双指针枚举b和c
				int j = i + 1, k = n - 1;
				while (j < k) {
						int sum = nums[i] + nums[j] + nums[k];
						// 如果和为target直接返回答案
						if (sum == target) {
								return target;
						}
						update(sum);
						if (sum > target) {
								// 如果和大于target，移动c对应的指针
								int k0 = k - 1;
								// 移动到下一个不相等的元素
								while (j < k0 && nums[k0] == nums[k]) {
										--k0;
								}
								k = k0;
						} else {
								// 如果小于 target，移动b对应的指针
								int j0 = j + 1;
								// 移动到下一个不相等的元素
								while (j0 < k && nums[j0] == nums[j]) {
										++j0;
								}
								j = j0;
						}
				}
		}
		return best;
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
	auto res = obj->threeSumClosest(nums, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
