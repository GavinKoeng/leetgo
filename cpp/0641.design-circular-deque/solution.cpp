// Created by Gavin at 2026/01/29 22:02
// leetgo: 1.4.15
// https://leetcode.cn/problems/design-circular-deque/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MyCircularDeque {
private:
    vector <int> element;
    int front, rear;
    int capacity;

public:
    MyCircularDeque(int k) {
        element = vector <int> (k + 1);
        rear = front = 0;
        capacity = k + 1;
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        element[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        element[rear] = value;
        rear = (rear + 1) % capacity;
        return true;        
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return element[front];
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return element[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return rear == front;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	MyCircularDeque *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "MyCircularDeque", [&]() {
			int k; LeetCodeIO::scan(cin, k); cin.ignore();
			obj = new MyCircularDeque(k);
			out_stream << "null,";
		} },
		{ "insertFront", [&]() {
			int value; LeetCodeIO::scan(cin, value); cin.ignore();
			LeetCodeIO::print(out_stream, obj->insertFront(value)); out_stream << ',';
		} },
		{ "insertLast", [&]() {
			int value; LeetCodeIO::scan(cin, value); cin.ignore();
			LeetCodeIO::print(out_stream, obj->insertLast(value)); out_stream << ',';
		} },
		{ "deleteFront", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->deleteFront()); out_stream << ',';
		} },
		{ "deleteLast", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->deleteLast()); out_stream << ',';
		} },
		{ "getFront", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->getFront()); out_stream << ',';
		} },
		{ "getRear", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->getRear()); out_stream << ',';
		} },
		{ "isEmpty", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->isEmpty()); out_stream << ',';
		} },
		{ "isFull", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->isFull()); out_stream << ',';
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
