// Created by Gavin at 2025/12/03 22:14
// leetgo: 1.4.15
// https://leetcode.cn/problems/can-place-flowers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int count = 0;
       int m = flowerbed.size();
       int prev = -1;
       for (int i = 0; i < m; i++) {
         if (flowerbed[i] == 1) {
           if (prev < 0) {
             count += i / 2;
           } else {
             count += (i - prev - 2) / 2;
            }
           prev = i;
         }
       }
       if (prev < 0) {
         count += (m + 1) / 2;
       } else {
         count += (m - prev - 1) / 2;
       }
       return count >= n;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> flowerbed;
	LeetCodeIO::scan(cin, flowerbed);
	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	auto res = obj->canPlaceFlowers(flowerbed, n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
