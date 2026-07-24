// Created by Gavin at 2025/12/08 15:59
// leetgo: 1.4.15
// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       for (int i = 0; i < numbers.size(); ++i) {
			   int low = i + 1, high = numbers.size() - 1;
			   while (low <= high) {
					   int mid = (high - low) / 2 + low;
					   if (numbers[mid] == target - numbers[i]) {
							   return {i + 1, mid + 1};
					   } else if (numbers[mid] > target - numbers[i]) {
							   high = mid - 1;
					   } else {
							   low = mid + 1;
					   }
			   }
	   }
	   return {-1, -1};
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> numbers;
	LeetCodeIO::scan(cin, numbers);
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->twoSum(numbers, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
