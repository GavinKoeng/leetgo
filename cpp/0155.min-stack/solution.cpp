// Created by gavin at 2026/08/11 23:42
// leetgo: 1.4.15
// https://leetcode.cn/problems/min-stack/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MinStack {
private:
    stack<pair<int, int>> stk;
public:
    MinStack() {
    }
    
    void push(int value) {
        if (stk.size() == 0) {
            stk.push({value, value});
        } else {
            stk.push({value, min(value, stk.top().second)});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	MinStack *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "MinStack", [&]() {
			cin.ignore();
			obj = new MinStack();
			out_stream << "null,";
		} },
		{ "push", [&]() {
			int value; LeetCodeIO::scan(cin, value); cin.ignore();
			obj->push(value);
			out_stream << "null,";
		} },
		{ "pop", [&]() {
			cin.ignore();
			obj->pop();
			out_stream << "null,";
		} },
		{ "top", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->top()); out_stream << ',';
		} },
		{ "getMin", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->getMin()); out_stream << ',';
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
