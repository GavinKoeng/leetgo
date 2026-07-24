// Created by Gavin at 2025/12/03 21:58
// leetgo: 1.4.15
// https://leetcode.cn/problems/lemonade-change/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      int five = 0, ten = 0;
      for (auto& bill:bills) {
        if (bill == 5) {
          five++;
        } else if (bill == 10) {
          if (five == 0) {
            return false;
          }
          five--;
          ten++;
        } else {
          if (five > 0 && ten > 0) {
            five--;
            ten--;
          } else if (five >= 3) {
            five -= 3;
          } else {
            return false;
          }
        }
      }
      return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> bills;
	LeetCodeIO::scan(cin, bills);

	Solution *obj = new Solution();
	auto res = obj->lemonadeChange(bills);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
