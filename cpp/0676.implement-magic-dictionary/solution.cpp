// Created by Gavin at 2026/01/19 16:40
// leetgo: 1.4.15
// https://leetcode.cn/problems/implement-magic-dictionary/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MagicDictionary {
public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }
    
    bool search(string searchWord) {
        for (auto&& word: words) {
            if (word.size() != searchWord.size()) {
                continue;
            }
            
            int diff = 0;
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] != searchWord[i]) {
                    ++diff;
                    if (diff > 1) {
                        break;
                    }
                }
            }
            if (diff == 1) {
                return true;
            }
        }
        return false;
    }

private:
    vector<string> words;
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	MagicDictionary *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "MagicDictionary", [&]() {
			cin.ignore();
			obj = new MagicDictionary();
			out_stream << "null,";
		} },
		{ "buildDict", [&]() {
			vector<string> dictionary; LeetCodeIO::scan(cin, dictionary); cin.ignore();
			obj->buildDict(dictionary);
			out_stream << "null,";
		} },
		{ "search", [&]() {
			string searchWord; LeetCodeIO::scan(cin, searchWord); cin.ignore();
			LeetCodeIO::print(out_stream, obj->search(searchWord)); out_stream << ',';
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
