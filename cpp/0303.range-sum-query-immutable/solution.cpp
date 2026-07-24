// Created by Gavin at 2026/02/02 10:20
// leetgo: 1.4.15
// https://leetcode.cn/problems/range-sum-query-immutable/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	NumArray *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "NumArray", [&]() {
			vector<int> nums; LeetCodeIO::scan(cin, nums); cin.ignore();
			int numsSize; LeetCodeIO::scan(cin, numsSize); cin.ignore();
			obj = new NumArray(nums, numsSize);
			out_stream << "null,";
		} },
		{ "sumRange", [&]() {
			int left; LeetCodeIO::scan(cin, left); cin.ignore();
			int right; LeetCodeIO::scan(cin, right); cin.ignore();
			LeetCodeIO::print(out_stream, obj->sumRange(left, right)); out_stream << ',';
		} },
	};
	cin >> ws;
	out_stream << '[';
	for (auto &&method_name : method_names) {
		cin.ignore(2);
		methods.at(method_name)();
	}
	cin.ignore();
	out_stream.seekp(-1, ios_base::end); out_stream << ']';
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
