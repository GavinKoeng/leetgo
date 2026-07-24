// Created by Gavin at 2025/12/09 16:57
// leetgo: 1.4.15
// https://leetcode.cn/problems/boats-to-save-people/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       int ans = 0;
	   sort(people.begin(), people.end());
	   int light = 0, heavy = people.size() - 1;
	   while (light <= heavy) {
			   if (people[light] + people[heavy] > limit) {
					   --heavy;
			   } else {
					   ++light;
					   --heavy;
			   }
			   ++ans;
	   }
	   return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> people;
	LeetCodeIO::scan(cin, people);
	int limit;
	LeetCodeIO::scan(cin, limit);

	Solution *obj = new Solution();
	auto res = obj->numRescueBoats(people, limit);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
