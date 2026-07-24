// Created by Gavin at 2025/12/11 11:26
// leetgo: 1.4.15
// https://leetcode.cn/problems/first-bad-version/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
		while (left < right) {
				int mid = left + (right - left) / 2;
				if (isBadVersion(mid)) {
						right = mid;
				} else {
						left = mid - 1;
				}
		}
		return left;

    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);
	int bad;
	LeetCodeIO::scan(cin, bad);

	Solution *obj = new Solution();
	//auto res = obj->firstBadVersion(n, bad);
	auto res = obj->firstBadVersion(n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
