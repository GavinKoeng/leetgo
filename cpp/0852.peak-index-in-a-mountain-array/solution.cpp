// Created by Gavin at 2025/12/12 10:32
// leetgo: 1.4.15
// https://leetcode.cn/problems/peak-index-in-a-mountain-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
		int n = arr.size();
		int ans = -1;
		for (int i = 1; i < n - 1; ++i) {
				if (arr[i] > arr[i + 1]) {
						ans = i;
						break;
				}
		}
		return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> arr;
	LeetCodeIO::scan(cin, arr);

	Solution *obj = new Solution();
	auto res = obj->peakIndexInMountainArray(arr);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
