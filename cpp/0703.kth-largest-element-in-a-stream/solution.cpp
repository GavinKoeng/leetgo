// Created by Gavin at 2025/12/30 01:00
// leetgo: 1.4.15
// https://leetcode.cn/problems/kth-largest-element-in-a-stream/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto& x : nums) {
            add(x);
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	KthLargest *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "KthLargest", [&]() {
			int k; LeetCodeIO::scan(cin, k); cin.ignore();
			vector<int> nums; LeetCodeIO::scan(cin, nums); cin.ignore();
			int numsSize; LeetCodeIO::scan(cin, numsSize); cin.ignore();
			obj = new KthLargest(k, nums, numsSize);
			out_stream << "null,";
		} },
		{ "add", [&]() {
			int val; LeetCodeIO::scan(cin, val); cin.ignore();
			LeetCodeIO::print(out_stream, obj->add(val)); out_stream << ',';
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
