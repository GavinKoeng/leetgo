// Created by Gavin at 2026/02/04 13:39
// leetgo: 1.4.15
// https://leetcode.cn/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
    vector<int> cnt;
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        cnt.resize(n + 1, 0);
        int odd = 0, ans = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            odd += nums[i] & 1;
            ans += odd >= k ? cnt[odd - k] : 0;
            cnt[odd]++;
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
	auto res = obj->numberOfSubarrays(nums, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
