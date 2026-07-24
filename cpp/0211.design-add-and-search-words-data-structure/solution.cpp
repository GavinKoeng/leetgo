// Created by Gavin at 2026/01/15 16:47
// leetgo: 1.4.15
// https://leetcode.cn/problems/design-add-and-search-words-data-structure/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

struct TrieNode{
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        this->child = vector<TrieNode *>(26, nullptr);
        this->isEnd = false;
    }
};

void insert(TrieNode * root, const string & word) {
    TrieNode * node = root;
    for (auto c : word) {
        if (node->child[c - 'a'] == nullptr) {
            node->child[c - 'a'] = new TrieNode();
        }
        node = node->child[c - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary {
public:
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        insert(trie, word);
    }
    
    bool search(string word) {
        return dfs(word, 0, trie);
    }

    bool dfs(const string & word, int index, TrieNode * node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            TrieNode * child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
            }
        } else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                TrieNode * child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                        return true;
                }
            }
        }
    return false;
    }
private:
    TrieNode * trie;
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	WordDictionary *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "WordDictionary", [&]() {
			cin.ignore();
			obj = new WordDictionary();
			out_stream << "null,";
		} },
		{ "addWord", [&]() {
			string word; LeetCodeIO::scan(cin, word); cin.ignore();
			obj->addWord(word);
			out_stream << "null,";
		} },
		{ "search", [&]() {
			string word; LeetCodeIO::scan(cin, word); cin.ignore();
			LeetCodeIO::print(out_stream, obj->search(word)); out_stream << ',';
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
