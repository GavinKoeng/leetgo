// Created by Gavin at 2025/12/15 02:27
// leetgo: 1.4.15
// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) {
          return combinations;
        }
        unordered_map<char, string> phoneMap{
          {'2', "abc"},
          {'3', "def"},
          {'4', "ghi"},
          {'5', "jkl"},
          {'6', "mno"},
          {'7', "pqrs"},
          {'8', "tuv"},
          {'9', "wxyz"},
        };
        string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
      if (index == digits.length()) {
        combinations.push_back(combination);
      } else {
        char digit = digits[index];
        const string& letters = phoneMap.at(digit);
        for (const char& letter: letters) {
          combination.push_back(letter);
          backtrack(combinations, phoneMap, digits, index + 1, combination);
          combination.pop_back();
        }
      }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string digits;
	LeetCodeIO::scan(cin, digits);

	Solution *obj = new Solution();
	auto res = obj->letterCombinations(digits);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
