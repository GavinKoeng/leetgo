// Created by Gavin at 2026/01/22 09:59
// leetgo: 1.4.15
// https://leetcode.cn/problems/find-median-from-data-stream/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;

    MedianFinder() {}
    
    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());
                queMin.pop();
            }
        } else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	MedianFinder *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "MedianFinder", [&]() {
			cin.ignore();
			obj = new MedianFinder();
			out_stream << "null,";
		} },
		{ "addNum", [&]() {
			int num; LeetCodeIO::scan(cin, num); cin.ignore();
			obj->addNum(num);
			out_stream << "null,";
		} },
		{ "findMedian", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->findMedian()); out_stream << ',';
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
