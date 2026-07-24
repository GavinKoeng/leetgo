// Created by Gavin at 2026/01/14 14:40
// leetgo: 1.4.15
// https://leetcode.cn/problems/implement-trie-prefix-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}
    
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	Trie *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "Trie", [&]() {
			cin.ignore();
			obj = new Trie();
			out_stream << "null,";
		} },
		{ "insert", [&]() {
			string word; LeetCodeIO::scan(cin, word); cin.ignore();
			obj->insert(word);
			out_stream << "null,";
		} },
		{ "search", [&]() {
			string word; LeetCodeIO::scan(cin, word); cin.ignore();
			LeetCodeIO::print(out_stream, obj->search(word)); out_stream << ',';
		} },
		{ "startsWith", [&]() {
			string prefix; LeetCodeIO::scan(cin, prefix); cin.ignore();
			LeetCodeIO::print(out_stream, obj->startsWith(prefix)); out_stream << ',';
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
