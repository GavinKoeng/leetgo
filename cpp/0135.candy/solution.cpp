// Created by Gavin at 2025/12/09 18:40
// leetgo: 1.4.15
// https://leetcode.cn/problems/candy/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
		vector<int> left(n);
		for (int i = 0; i < n; i++) {
				if (i > 0 && ratings[i] > ratings[i - 1]) {
						left[i] = left[i - 1] + 1;
				} else {
						left[i] = 1;
				} 
		}
		int right = 0, ret = 0;
		for (int i = n - 1; i >= 0; i--) {
				if (i < n - 1 && ratings[i] > ratings[i + 1]) {
						right++;
				} else {
						right = 1;
				}
				ret += max(left[i], right);
		}
		return ret;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> ratings;
	LeetCodeIO::scan(cin, ratings);

	Solution *obj = new Solution();
	auto res = obj->candy(ratings);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
