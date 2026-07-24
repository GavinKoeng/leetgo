// Created by Gavin at 2025/12/09 17:29
// leetgo: 1.4.15
// https://leetcode.cn/problems/gas-station/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
		int i = 0;
		while (i < n) {
				int sum0fGas = 0, sum0fCost = 0;
				int cnt = 0;
				while (cnt < n) {
						int j = (i + cnt) % n;
						sum0fGas += gas[j];
						sum0fCost += cost[j];
						if (sum0fCost > sum0fGas) {
								break;
						}
						cnt++;
				}
				if (cnt == n) {
						return i;
				} else {
						i = i + cnt + 1;
				}
		}
		return -1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> gas;
	LeetCodeIO::scan(cin, gas);
	vector<int> cost;
	LeetCodeIO::scan(cin, cost);

	Solution *obj = new Solution();
	auto res = obj->canCompleteCircuit(gas, cost);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
