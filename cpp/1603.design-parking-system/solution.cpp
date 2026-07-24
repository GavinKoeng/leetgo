// Created by Gavin at 2025/12/27 21:17
// leetgo: 1.4.15
// https://leetcode.cn/problems/design-parking-system/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small): b(big), m(medium), s(small) {}
    
    bool addCar(int carType) {
        if (carType == 1) {
            if (b > 0) {
                b--;
                return true;
            }
        } else if (carType == 2) {
            if (m > 0) {
                m--;
                return true;
            }
        } else if (carType == 3) {
            if (s > 0) {
                s--;
                return true;
            }
        }
        return false;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	ParkingSystem *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "ParkingSystem", [&]() {
			int big; LeetCodeIO::scan(cin, big); cin.ignore();
			int medium; LeetCodeIO::scan(cin, medium); cin.ignore();
			int small; LeetCodeIO::scan(cin, small); cin.ignore();
			obj = new ParkingSystem(big, medium, small);
			out_stream << "null,";
		} },
		{ "addCar", [&]() {
			int carType; LeetCodeIO::scan(cin, carType); cin.ignore();
			LeetCodeIO::print(out_stream, obj->addCar(carType)); out_stream << ',';
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
